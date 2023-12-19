#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "init.h"

void sqlExec(char *sql)
{
   char *zErrMsg = 0;
   int rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

   if (rc != SQLITE_OK)
   {
      fprintf(stderr, "ERROR::%s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }
}

void sqlInit(char *file)
{
   char *path = (char*)malloc(sizeof(char) * (PATH_SIZE + 1));

   strcpy(path, "db/");
   strcat(path, file);

   FILE *fp = fopen(path, "r");

   if (fp == NULL)
   {
      fprintf(stderr, "ERROR::sqlInit()\n");
      exit(EXIT_FAILURE);
   }

   char *sql = (char*)malloc(sizeof(char) * (LINE_SIZE + 1));

   while (fgets(sql, LINE_SIZE, fp) != NULL)
   {
      sqlExec(sql);
   }

   fclose(fp);
}

void loadRepl()
{
   char *sql = (char*)malloc(sizeof(char) * (LINE_SIZE + 1));

   while (1)
   {
      fgets(sql, LINE_SIZE, stdin);

      if (strcmp(sql, "q\n") == 0)
      {
         return;
      }

      sqlExec(sql);

      printf("INPUT::%s", sql);
   }
}

void __attribute__ ((constructor)) initLibrary(void)
{
   int rc = sqlite3_open("db/test.db", &db);

   if (rc)
   {
      fprintf(stderr, "ERROR::%s\n", sqlite3_errmsg(db));
      exit(EXIT_FAILURE);
   }

   glfwSetErrorCallback(error_callback);

   if (!glfwInit())
   {
      fprintf(stderr, "ERROR::glfwinit()\n");
      exit(EXIT_FAILURE);
   }

   glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
   glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
   glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

   printf("LIBRARY::init\n"); 
}

void __attribute__ ((destructor)) cleanUpLibrary(void)
{
   sqlite3_close(db);
   glfwTerminate();

   printf("LIBRARY::exit\n"); 
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

static void error_callback(int error, const char* description)
{
   fprintf(stderr, "ERROR::%s\n", description);
}
