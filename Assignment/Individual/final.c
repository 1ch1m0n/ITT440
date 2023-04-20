#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

void parentTask(); // function definition
void childTask();
void sigint_handler(int a);

int pipefds[2]; // array to store pipe file descriptors


int main()
{
        // create pipe
        if (pipe(pipefds) == -1)
        {
                perror("pipe");
                exit(EXIT_FAILURE);
        }

        // fork child processes
        for (int i = 0; i < 2; i++)
        {
                pid_t pid = fork();

                if (pid > 0) // parent process
                {
                        parentTask();
                }
                else if (pid == 0) // child process
                {
                        childTask();
                }
                else
                {
                        perror("fork");
                        exit(EXIT_FAILURE);
                }
        }

        // wait for child processes to exit
        int status;
        for (int i = 0; i < 2; i++)
        {
            wait(&status);
        }

        return 0;
}

void parentTask()
{
        // parent process
        close(pipefds[0]); // close read end of pipe
        char buffer[100];
        printf("Enter a message: ");
        while (fgets(buffer, 100, stdin) != NULL)
        {
                signal(SIGINT, sigint_handler); // interrupt handler

                // write message to pipe
                if (write(pipefds[1], buffer, strlen(buffer) + 1) == -1)
                {
                        perror("write");
                        exit(EXIT_FAILURE);
                }

                printf("Message sent to children.\n");

                printf("Enter a message: ");
        }
}

void childTask()
{
        // child process
        close(pipefds[1]); // close write end of pipe
        char childbuffer[100];
        while (read(pipefds[0], childbuffer, 100) > 0)
        {
                printf("Child process received message: %s", childbuffer);
        }
        exit(0);
}

// interrupt handler for SIGINT (Ctrl + C)
void sigint_handler(int a)
{
        printf("\nInterrupt signal received. Exiting program.\n");
        exit(1);
}
