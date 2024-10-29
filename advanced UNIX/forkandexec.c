#include "apue.h"

int main(int argc, char *argv[])
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

    printf("%% "); /* print prompt (printf requires %% to print %) */
    while (fgets(buf, MAXLINE, stdin) != NULL)
    {
        if (buf[strlen(buf) - 1] == '\n') 
        {
            buf[strlen(buf) - 1] = 0; /* replace newline with null */
        }

        if ((pid = fork()) < 0)
        {
            printf("fork error");
        }
        else if (pid == 0)
        {
            execlp(buf, buf, (char *)0);
            printf("couldn't execute: %s \n", buf);
            exit(127);
        }

        if ((pid = waitpid(pid, &status, 0)) < 0)
        {
            printf("waitpid error");
        }

        printf("%% ");

    }

    return 0;
}