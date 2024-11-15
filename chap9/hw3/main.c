#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 1024

int main() {
    char command[MAX_CMD_LENGTH];
    while (1) {
        printf("[shell] ");
        if (fgets(command, MAX_CMD_LENGTH, stdin) == NULL) {
            break;
        }

        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "exit") == 0) {
            break;
        }

        char *token = strtok(command, ";");
        while (token != NULL) {
            if (strchr(token, '&') != NULL) {
                pid_t pid = fork();
                if (pid == -1) {
                    perror("fork error");
                    exit(EXIT_FAILURE);
                }
                if (pid == 0) {
                    char *args[] = {"/bin/sh", "-c", token, NULL};
                    execvp(args[0], args);
                    perror("exec error");
                    exit(EXIT_FAILURE);
                }
            } else {
                pid_t pid = fork();
                if (pid == -1) {
                    perror("fork error");
                    exit(EXIT_FAILURE);
                }
                if (pid == 0) {
                    char *args[] = {"/bin/sh", "-c", token, NULL};
                    execvp(args[0], args);
                    perror("exec error");
                    exit(EXIT_FAILURE);
                } else {
                    int status;
                    waitpid(pid, &status, 0);
                }
            }
            token = strtok(NULL, ";");
        }
    }
    return 0;
}
