#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]){

        int fd;
        char saveText[BUFSIZE][BUFSIZE];
        ssize_t nread;
        char input[BUFSIZE];
        int line_total=0;
		char buf[1];
		int i=0;
		int j=0;
        if((fd = open(argv[1], O_RDONLY)) ==-1){
                perror(argv[1]);
        exit(1);
        }
		while((nread=read(fd,buf,1)) > 0){
                if(buf[0]=='\n'){
                        saveText[i][j] = '\0';
                        i++;
                        j=0;
                }
                else {
                        saveText[i][j] = buf[0];
                        j++;
                        }
                }
        line_total=i;
        close(fd);
		for(int i=line_total-1;i>=0;i--){
			printf("%s\n",saveText[i]);
		}
		return 0;
}
	
