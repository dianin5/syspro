#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <command1> <command2>\n", argv[0]);
        exit(1);
    }

    int pipefd[2];
    pid_t pid1, pid2;

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(1);
    }

    pid1 = fork();
    if (pid1 == 0) {
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);

        char *cmd1[] = {"/bin/sh", "-c", argv[1], NULL};
        execv("/bin/sh", cmd1);
        perror("execv");
        exit(1);
    }

    pid2 = fork();
    if (pid2 == 0) {
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);

        char *cmd2[] = {"/bin/sh", "-c", argv[2], NULL};
        execv("/bin/sh", cmd2);
        perror("execv");
        exit(1);
    }

    close(pipefd[0]);
    close(pipefd[1]);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return 0;
}

