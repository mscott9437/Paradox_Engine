#include <stdio.h>
 
void main()
{
   char *cmd = "hello.okay[0]";

   printf("%s\n", cmd);

   char out[13];

   for(int i = 0; cmd[i] != '\0'; i++)
   {
      out[i] = cmd[i] + 1;
      printf("%c", out[i]);
   }

   return;
}
