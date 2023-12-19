const std = @import("std");

const c = @cImport({@cInclude("sqlite3.h");});

const max_size = 65536;

pub fn main() !void {

   var raw_db: ?*c.sqlite3 = undefined;

   var rc: i32 = c.sqlite3_open("db/main.db", &raw_db);
   defer _ = c.sqlite3_close(raw_db);

   var db: *c.sqlite3 = @ptrCast(*c.sqlite3, raw_db);

   var my_file = try std.fs.cwd().openFile("ss/init.sql", .{},);
   defer my_file.close();

   var sql: [*c]const u8 = undefined;
   var f_buf: [max_size]u8 = undefined;

   while (try my_file.reader().readUntilDelimiterOrEof(&f_buf, '\n')) |line| {
      sql = @ptrCast([*c]const u8, line);
      rc = c.sqlite3_exec(db, sql, null, null, null);
   }

   const stdin = std.io.getStdIn();
   var in_buf: [max_size + 2]u8 = undefined;

   while (true) {
      var input = (try stdin.reader().readUntilDelimiterOrEof(&in_buf, '\n',)).?;
      std.debug.print("{s}\n", .{input},);
   }

}

fn cb(data: ?*c.c_void, argc: c.c_int, argv: [*c][*c]u8, azColName: [*c][*c]u8) callconv(.C) c.c_int {
   var i: usize = 0;

   while (i < argc) {
      if (argv[i] != null) {
         std.debug.warn("{s} = {s}\n", .{ azColName[i], argv[i] });
      } else {
         std.debug.warn("{s} = {}\n", .{ azColName[i], "NULL" });
      }
      i += 1;
   }
   std.debug.warn("\n", .{});
   return 0;
}

pub fn exec(db: *sqlite3, sql: [*:0]const u8, callback: fn(?*c_void, c_int, [*c][*c]u8, [*c][*c]u8) callconv(.C) c_int) !void {
   var errmsg: ?[*:0]u8 = undefined;
   var rc = sqlite3_exec(db, sql, callback, null, &errmsg);
   switch (rc) {
      SQLITE_OK => {
         return;
      },
      SQLITE_ERROR => {
         return Error.Error;
      },
      else => {
         std.debug.warn("{}: {s}\n", .{rc, errmsg});
         return Error.Unimplemented;
      },
   }
   if (rc != SQLITE_OK) {
      sqlite3_free(errmsg);
   }
}
