#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

void myls(const char *str)
{
	struct dirent *dirp;
	DIR *dp = opendir(str);
	if(!dp)
	{
		perror("open dir failed:");
		return;
	}

	while((dirp = readdir(dp)) != NULL)
	{

		if( strcmp(dirp->d_name,".") != 0 && strcmp(dirp->d_name,"..") != 0)
			printf("%s\n", dirp->d_name);
	}
	closedir(dp);
}

int main(int argc, char *argv[])
{
	if(argc > 3)
	{
		fprintf(stderr,"格式错误！");
		return -1;
	}
	else if(1 == argc)
	{
		 myls(".");
	}
	else
	{
		myls(argv[1]);
	}
}














