#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "student.h"
#include <errno.h>
#include <string.h>
int main(int argc, char* argv[]){
	int fd,id;
	struct student record;
	struct flock lock;

	if(argc <2){
		fprintf(stderr, "How to use: %s File\n", argv[0]);
		exit(1);
	}
	if((fd = open(argv[1], O_RDWR)) == -1){
		perror(argv[1]);
		exit(2);
	}
	printf("\nEnter StudentID you want to modify : ");
	while(scanf("%d",&id)==1){
		memset(&lock,0,sizeof(lock));
		lock.l_type = F_WRLCK;
		lock.l_whence = SEEK_SET;
		lock.l_start =(id - START_ID) * sizeof(record);
		lock.l_len=sizeof(record);
		if(fcntl(fd, F_SETLKW,&lock)==-1){
			perror("fcntl");
			printf("errno: %d\n",errno);
			exit(3);
		}
		lseek(fd,(long)(id-START_ID)*sizeof(record),SEEK_SET);
		if((read(fd,(char *) &record, sizeof(record)) > 0) &&(record.id !=0)){
				printf("Name:%s\t StuID:%d\t Score:%d\n",record.name, record.id, record.score);
				printf("Enter new scord: ");
				scanf("%d", &record.score);
				lseek(fd, (long) -sizeof(record),SEEK_CUR);
				write(fd, (char *) &record, sizeof(record));
				lock.l_type = F_UNLCK;
				fcntl(fd, F_SETLK, &lock);
				}
		else printf("No record %d \t",id);
		printf("\nEnter StudentID you wnat to modify : ");
	}
	close(fd);
	exit(0);
}
