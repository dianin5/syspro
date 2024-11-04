#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>

int main(int argc,char* argv[]){
	char **ptr;
    extern char **environ;
    char *ptr_one;

    if(argc == 1){
        perror(argv[1]);
        return 1;
    }
	if(strcmp(argv[1], "-e") == 0){
        if(argc > 2){
            ptr_one = getenv(argv[2]);
            printf("%s = %s \n", argv[2], ptr_one);
            
        }else{
            for(ptr = environ; *ptr != 0; ptr++)
                printf("%s \n", *ptr);
        }
	}

	else if (strcmp(argv[1],"-u")==0){
		printf("my UID : %d(%s) \n",getuid(),getpwuid(getuid())->pw_name);
		printf("my EUID : %d(%s) \n",geteuid(),getpwuid(geteuid())->pw_name);
	}
	else if(strcmp(argv[1], "-g")==0){
		printf("my GID : %d(%s) \n",getgid(),getgrgid(getgid())->gr_name);
		printf("my EGID : %d(%s) \n",getegid(),getgrgid(getegid())->gr_name);
	}
	else if(strcmp(argv[1], "-i")==0){
		printf("my PID : [%d] \n",getpid());
	}
	else if(strcmp(argv[1], "-p")==0){
		printf("my PPID : [%d] \n",getppid());
	}
	return 0;
		}
