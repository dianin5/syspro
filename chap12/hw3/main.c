#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#define READ 0
#define WRITE 1

int main() {
    char str[1024];
    char *command1, *command2;
    int fd[2];

    printf("[shell] ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 0;
    }

    str[strlen(str) - 1] = '\0'; // '\n' 제거

    if (strchr(str, '|') != NULL) {
        command1 = strtok(str, "|");
        command2 = strtok(NULL, "|");

        if (command1 != NULL) {
            command1 = strtok(command1, " "); // 명령어 정리
        }
        if (command2 != NULL) {
            command2 = strtok(command2, " "); // 명령어 정리
        }
    } else {
        fprintf(stderr, "Invalid command. Use the format: <command1> | <command2>\n");
        return 1;
    }

    pipe(fd);

    if (fork() == 0) { 
        close(fd[READ]);
        dup2(fd[WRITE], STDOUT_FILENO);
        close(fd[WRITE]);
        execlp(command1, command1, NULL);
        perror("execlp");
        exit(1);
    }

    if (fork() == 0) { 
        close(fd[WRITE]);
        dup2(fd[READ], STDIN_FILENO);
        close(fd[READ]);
        execlp(command2, command2, NULL);
        perror("execlp");
        exit(1);
    }

    close(fd[READ]);
    close(fd[WRITE]);
    wait(NULL);
    wait(NULL);

    return 0;
}

