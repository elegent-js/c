
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT 1024
#define MAX_ARGS 64

void run_shell();

int main(int argc, char *args[]) {
    run_shell();
    return 0;
}

/**
 * 运行shell
 */
void run_shell() {
    char input[MAX_INPUT];
    char *args[MAX_ARGS];

    while (1) {
        printf("mysh> ");
        fflush(stdout);

        // Ctrl + D退出
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        // 去除换行符
        input[strcspn(input, "\n")] = '\0';

        // 如果是exit
        if(strcmp(input, "exit") == 0) {
            break;
        }

        int argc = 0;
        char *token = strtok(input, " ");
        while (token != NULL && argc < MAX_ARGS - 1) {
            args[argc ++] = token;
            token = strtok(NULL, " ");
        }

        args[argc] = NULL;

        if (argc == 0) {
            continue;
        }

        // 如果当前是cd命令
        if (strcmp(args[0], "cd") == 0) {
            if (argc < 2) {
                fprintf(stderr, "cd: missing operand.\n");
            } else if (chdir(args[1]) != 0) {
                perror("cd failed.");
            }

            continue;
        }

        // 创建子进程
        pid_t pid = fork();
        if (pid == 0) {
            // 子进程
            execvp(args[0], args);
            perror("exec failed");
            exit(1);
        } else if (pid > 0) {
            // 父进程等待子进程
            waitpid(pid, NULL, 0);
        } else {
            perror("fork failed");
        }

    }
    
}