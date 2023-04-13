#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
int main(void)
{
   void sigint_handler(int a);
   void sigtstp_handler(int b);
   void sigquit_handler(int c);
   char s[200];

   if (signal(SIGINT, sigint_handler) == SIG_ERR){
      perror("signal");
      exit(1);
   }
   if (signal(SIGTSTP,sigtstp_handler) == SIG_ERR){
      perror("signal");
      exit(1);
   }
   if (signal(SIGQUIT,sigquit_handler) == SIG_ERR){
      perror("signal");
      exit(1);
   }
   printf("Enter a string:\n");
   if (fgets(s, 200, stdin) == NULL){
      perror("gets");
      perror("gets");
      perror("gets");
   }
   
 return 0;
}
void sigint_handler(int a)
{
   printf("This is a special handler for SIGINT \n"); //CTRL + C 
}
void sigtstp_handler(int b)
{
   printf("This is a special handler for SIGTSTP \n"); //CTRL + Z
}
void sigquit_handler(int c)
{
   printf("This is a special handler for SIGQUIT \n"); //CTRL + \
}
