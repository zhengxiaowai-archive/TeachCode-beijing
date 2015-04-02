#include <sys/types.h>
#include <sys/shm.h>
#include <stdio.h>
#include <errno.h>

int main (int argc, char *argv[])
{
	char *men_addr = NULL;
	int shmid = 32768;
	men_addr = shmat (shmid, 0, 0);
	if (NULL == men_addr)
	{
		return -1;
	}

	sprintf (men_addr, "%s", "hello world");
	shmdt (men_addr);
	return 0;

}
