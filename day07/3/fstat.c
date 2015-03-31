#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	struct stat st;
	int s = stat("a.txt", &st);
	if( 0 == s)
	{
		printf("%d\n", (int)st.st_size);
	}

	
	return 0;
}
