#include <stdio.h>
#include "copy.h"
#include <string.h>
char line [MAXLINE];
char lines [MAXLINE][MAXLINE];

int main(){
	int len;
	int max;
	max =0;
	int count=0;
	while(count < 5){
		gets(lines[count]);
		count++;
}

for(int i=0; i< count -1; i++){
	for(int j=0; j<count -1; j++){
		if(strlen(lines[i])>strlen(lines[j])){
			char temp[MAXLINE];
			copy(lines[i], temp);
			copy(lines[j], lines[i]);
			copy(temp, lines[j]);
		}
	}
}
for (int i=0; i<count; i++){
	printf("%s\n",lines[i]);
}
return 0;
}
