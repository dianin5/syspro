#include <stdio.h>
#include <stdlib.h>
#define False 0
#define True 1
struct book{
	int id;
	char bookname[20];
	char author[20];
	int year;
	int numofborrow;
	int borrow;
};

int main(int argc, char* argv[]){
	struct book rec;
	FILE *fp;
	fp=fopen(argv[1],"wb");
	printf("%-9s %s %s %s %s %s\n", "id", "bookname", "author", "year", "numofborrow","borrow");
	while (scanf("%d %s %s %d %d %d %d", &rec.id, rec.bookname, rec.author, &rec.year, &rec.numofborrow, &rec.borrow)==6)
		fwrite(&rec,sizeof(rec), 1, fp);
		fclose(fp);
	exit(0);
}
