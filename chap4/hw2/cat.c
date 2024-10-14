#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 80
int main(int argc, char *argv[]){
	FILE *fp;
	int c;
	int i=1;
	int line =0;
	char buffer[MAXLINE];
	if(argc<2)
		fp=stdin;
	else{
		if (strcmp(argv[1], "-n")==0){
			if ((fp=fopen(argv[2],"r")) ==NULL){
				fprintf(stderr,"Error Open File\n");
				exit(2);
			}
			while(fgets(buffer,MAXLINE,fp)!= NULL){
				line++;
				printf("%3d %s",line,buffer);
			}
			line =0;
			exit(0);
		}
		else{
			while(argv[i] !=NULL){
			fp = fopen(argv[i],"r");
			c= getc(fp);
			while( c!= EOF){
				putc(c, stdout);
				c=getc(fp);}
			i++;
			fclose(fp);
		}
		}
	return 0;
}
}

