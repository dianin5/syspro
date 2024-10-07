#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define BUFSIZE 1024
int main(int argc, char*argv[])
{
	int fd;
	char saveText[BUFSIZE][BUFSIZE];
	ssize_t nread;
	char input[BUFSIZE];
	int line_total=0;
	if((fd = open(argv[1], O_RDONLY)) ==-1){
		perror(argv[1]);
	exit(1);
	}
	int count=0;
	char buf[1];
	int i=0,j=0;
	printf("File read success");
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
	printf("Total Line : %d\n",line_total);
	printf("You can choose 1 ~ %d Line\n",line_total);
	printf("Pls 'Enter' The line to select : ");
	scanf("%s",input);
	if(strcmp(input,"*")==0){
		for(int k=0; k<line_total;k++)
			printf("%s\n",saveText[k]);
	}
	else if(input[1] == '-'){
		int start= input[0]-'0';
		int end =input[2]-'0';
		for(int k= start-1; k<=end-1;k++){
			printf("%s\n", saveText[k]);
		}
	}
	else if(strchr(input,',')!=NULL){
		int line=0;
		int k=0;
		while(input[k] !='\0'){
			if(input[k]>='0'&& input[k] <='9')
				line = line *10 +(input[k]- '0');
			
			if(input[k]==','||input[k+1]=='\0'){
				if(line>0&& line <=line_total)
					printf("%s\n",saveText[line-1]);
				else
					printf("%d is maximum\n",line_total);
				line=0;
			}
			k++;
		}
	}
	else{
		int line=input[0]-'0';
		if(line>0 && line<=line_total)
			printf("%s\n",saveText[line-1]);
		else
			printf("choose 1~ %d\n",line_total);
		}

	return 0;
	}
