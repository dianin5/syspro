#include <stdio.h>
#include <string.h>
#define MAX_LEN 10000
int main(int argc, char *argv[]){
	FILE *fp;
	int c;
	int user_input;
	char str[10000];
	fp =fopen("db.dat","r");
	printf("--bookquery--\n");
	printf("0: list of all books, 1: list of available books )");
	scanf("%d",&user_input);

		if (user_input==0){
			c= getc(fp);
			while(c != EOF){
				putc(c, stdout);
				c= getc(fp);
			}
			fclose(fp);
			return 0;
		}
		if (user_input==1){
			c= getc(fp);
			while(c != EOF){
				putc(c, stdout);
				c= getc(fp);
			}
			fclose(fp);
			return 0;
			
		}
}
