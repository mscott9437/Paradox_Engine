#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sqlite3.h>

#define PATH_SIZE 256
#define LINE_SIZE 65536

static int callback(void *NotUsed, int argc, char **argv, char **azColName);

int main(int argc, char **argv) {

   sqlite3* db;
   char *zErrMsg = 0;
   int rc = sqlite3_open("./tmp/test.db", &db);

   if (rc)
   {
      fprintf(stderr, "ERROR::%s\n", sqlite3_errmsg(db));
      exit(EXIT_FAILURE);
   }

   char *path = (char*)malloc(sizeof(char) * (PATH_SIZE + 1));

   FILE *fp = fopen("./tmp/init.sql", "r");

   if (fp == NULL)
   {
      fprintf(stderr, "ERROR::init.sql\n");
      exit(EXIT_FAILURE);
   }

   char *sql = (char*)malloc(sizeof(char) * (LINE_SIZE + 1));

   while (fgets(sql, LINE_SIZE, fp) != NULL)
   {
      rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

      if (rc != SQLITE_OK)
      {
         fprintf(stderr, "ERROR::%s\n", zErrMsg);
         sqlite3_free(zErrMsg);
      }
   }

   fclose(fp);

   while (fgets(sql, LINE_SIZE, stdin))
   {
      if (strcmp(sql, "q\n") == 0)
      {
         sqlite3_close(db);
         return 0;
      }

      rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

      if (rc != SQLITE_OK)
      {
         fprintf(stderr, "ERROR::%s\n", zErrMsg);
         sqlite3_free(zErrMsg);
      }

      printf("INPUT::%s", sql);
   }
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
   for(int i = 0; i < argc; i++) 
   {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("%s\n", "-");

   return 0;
}
