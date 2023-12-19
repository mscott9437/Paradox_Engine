#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 65536

int main(int argc, char **argv)
{
   FILE *fp = fopen("tmp/dat", "r");

   if (fp == NULL)
   {
      fprintf(stderr, "ERROR::fopen()\n");
      exit(EXIT_FAILURE);
   }

   char *sql = (char*)malloc(sizeof(char) * (LINE_SIZE + 1));

   while (fgets(sql, LINE_SIZE, fp) != NULL)
   {
      printf("%s", sql);
   }

   fclose(fp);

   fp = fopen("key", "w");

   if (fp == NULL)
   {
      fprintf(stderr, "ERROR::fopen()\n");
      exit(EXIT_FAILURE);
   }

   fprintf(fp, "%s %s %s %d", "We", "are", "in", 2012);

   fclose(fp);

   while(fgets(sql, LINE_SIZE, stdin))
   {
      printf("INPUT::%s", sql);
   }

   printf("%s", "okay");

   return 0;

   FILE *fp = fopen("./tmp", "w");

   if (fp == NULL)
   {
      fprintf(stderr, "ERROR::fopen()\n");
      exit(EXIT_FAILURE);
   }

   char *sql = (char*)malloc(sizeof(char) * (MAX_SIZE_16 + 1));

   while (fgets(sql, MAX_SIZE_16, stdin))
   {
      if (strcmp(sql, "q") == 0)
      {
         fclose(fp);
         printf("%s\n", "okay");
         return 0;
      }

      fprintf(fp, "%s", sql);
      printf("INPUT::%s", sql);
   }
}
