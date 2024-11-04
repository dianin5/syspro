#include <stdio.h>
#include <unistd.h>

int main(){
	printf("my PID : [%d] \n", getpid());
	printf("my PPID : [%d] \n", getppid());
}
