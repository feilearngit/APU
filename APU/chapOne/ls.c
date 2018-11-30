#include <apue.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
	DIR 		*dp;
	struct dirent *dirp;
	int 		tmp;
	tmp = argc;
	printf("ls test from process ID %d\n", getpid());
	printf("%d\n", argc);
	while(tmp)
		printf("%s\n", argv[--tmp]);
	
	if (argc != 2)
		err_quit("usage: ls directory_name");
	
	if((dp = opendir(argv[1])) == NULL)
		err_sys("can't open %s", argv[1]);
	
	while((dirp = readdir(dp)) != NULL)
		printf("%s\n", dirp->d_name);

	closedir(dp);
	exit(0);  //0是正常结束，1~255是出错



}
