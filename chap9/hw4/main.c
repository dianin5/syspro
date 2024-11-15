#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAXARG 128
#define MAX_CMD_LENGTH 1024

int main() {
    char command[MAX_CMD_LENGTH];
    char *args[MAXARG];
    int command_count = 0;

    while (command_count < 3) {
        printf("Pls input cmd : ");
        fflush(stdout);
        if (fgets(command, MAX_CMD_LENGTH, stdin) == NULL) {
            break;
        }

        command[strcspn(command, "\n")] = 0;

        char *token = strtok(command, " ");
        int i = 0;
        while (token != NULL && i < MAXARG - 1) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        pid_t pid = fork();
        if (pid == -1) {
            perror("fork error");
            exit(EXIT_FAILURE);
        }
        if (pid == 0) {
            if (execvp(args[0], args) == -1) {
                perror("exec error");
                exit(EXIT_FAILURE);
            }
        } else {
            if (strchr(command, '&') == NULL) {
                int status;
                waitpid(pid, &status, 0);
                printf("SUCCESS\n");
            }
        }
        command_count++;
    }
    printf("Parent process end\n");
    printf("EXIT\n");
    return 0;
}

