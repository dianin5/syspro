#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int main() {
    int pipe1[2], pipe2[2];
    pid_t pid1, pid2;
    char input[128], buffer[128];

    pipe(pipe1);
    pipe(pipe2);

    pid1 = fork();
    if (pid1 == 0) {
        close(pipe1[0]);
        close(pipe2[0]);
        close(pipe2[1]);

        printf("parent process start\n");
        printf("input string: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
        write(pipe1[1], input, strlen(input) + 1);
        close(pipe1[1]);
        return 0;
    }

    pid2 = fork();
    if (pid2 == 0) {
        close(pipe1[1]);
        close(pipe2[0]);

        read(pipe1[0], buffer, sizeof(buffer));
        for (int i = 0; buffer[i]; i++) {
            buffer[i] = toupper(buffer[i]);
        }
        write(pipe2[1], buffer, strlen(buffer) + 1);

        close(pipe1[0]);
        close(pipe2[1]);
        return 0;
    }

    close(pipe1[0]);
    close(pipe1[1]);
    close(pipe2[1]);

    read(pipe2[0], buffer, sizeof(buffer));
    printf("%s\n", buffer);
    close(pipe2[0]);

    return 0;
}

