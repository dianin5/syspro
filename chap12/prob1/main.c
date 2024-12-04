#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define MAXLINE 100

int main() {
    int n, fd[2], pid;
    char message[MAXLINE], line[MAXLINE];

    pipe(fd);

    if ((pid = fork()) == 0) {
        close(fd[0]);
        dup2(fd[1], 1);
        close(fd[1]);
    } else {
        close(fd[1]);
        printf("[%d] Hello from PID %d\n",getpid(),pid);
        while ((n = read(fd[0], line, MAXLINE)) > 0) {
            write(STDOUT_FILENO, line, n);
        }

    exit(0);
}
}
