#include <stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

int main(){
	printf("my UID : %d(%s) \n",getuid(),getpwuid(getuid())->pw_name);
	printf("my EUID : %d(%s) \n", geteuid(),getpwuid(geteuid())->pw_name);
	printf("my GID : %d(%s) \n",getgid(),getgrgid(getgid())->gr_name);
	printf("my EGID : %d(%s) \n",getegid(),getgrgid(getegid())->gr_name);
}
