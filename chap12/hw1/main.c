#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int pipefd1[2], pipefd2[2];
    char send_msg[32], recv_msg[32];
    pid_t parent_pid, child_pid;

    pipe(pipefd1);
    pipe(pipefd2);

    parent_pid = getpid();

    pid_t pid = fork();

    if (pid == 0) {
        close(pipefd1[0]);
        close(pipefd2[1]);

        child_pid = getpid();
        snprintf(send_msg, sizeof(send_msg), "Hello from PID %d", child_pid);
        write(pipefd1[1], send_msg, sizeof(send_msg));
        read(pipefd2[0], recv_msg, sizeof(recv_msg));
        printf("Send: [%d] %s\n", child_pid, send_msg);

        close(pipefd1[1]);
        close(pipefd2[0]);
    } else {
        close(pipefd1[1]);
        close(pipefd2[0]);

        snprintf(send_msg, sizeof(send_msg), "Hello from PID %d", parent_pid);
        write(pipefd2[1], send_msg, sizeof(send_msg));
        read(pipefd1[0], recv_msg, sizeof(recv_msg));
        printf("Recv: [%d] %s\n", parent_pid, recv_msg);

        close(pipefd1[0]);
        close(pipefd2[1]);
    }

    return 0;
}

