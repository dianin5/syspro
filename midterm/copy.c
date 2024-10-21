#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char* argv[]){
	char c;
	FILE *fp1, *fp2;
	int a=0,b=0,d=0;
	if (argc !=4){
		fprintf(stderr, "How to use:%s File1 File2\n",argv[0]);
		return 1;
		}
	for (int i=1; i<argc;i++){
		if(strcmp(argv[i], "0")==0)
			a=1;
		else if(strcmp(argv[i], "1")==0)
			b=1;
		else if(strcmp(argv[i], "2")==0)
			d=1;
	}
	if(a){

		fp1=fopen(argv[2],"r");
		if(fp1 ==NULL){
			fprintf(stderr,"File %s Open Error\n",argv[1]);
			return 2;
		}
		fp2 =fopen(argv[3],"w");
		while((c=fgetc(fp1))!=EOF)
			fputc(c,fp2);
		fclose(fp1);
		fclose(fp2);
		return 0;
	}
	if(b){
		fp1=fopen(argv[2],"r");
		if(fp1==NULL){
			fprintf(stderr,"File %s Open Error\n",argv[1]);
			return 2;
		}
		fp2 = fopen(argv[3],"w");
		while(1){
			c=fgetc(fp1);
			if(c==EOF)
				break;
			fputc(tolower(c), fp2);
		}
		fclose(fp1);
		fclose(fp2);
		return 0;
	}
	if(d){
		fp1 = fopen(argv[2], "r");
		if (fp1 == NULL) {
			fprintf(stderr, "File %s Open Error\n", argv[1]);
			return 2;
		}
		fp2 = fopen(argv[3], "w");
		while ((c = fgetc(fp1)) != EOF)
			fputc(toupper(c), fp2);
		fclose(fp1);
		fclose(fp2);
		return 0;
	}
}
