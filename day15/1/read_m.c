#include <sys/types.h>
#include <sys/shm.h>
#include <stdio.h>
#include <errno.h>

int main ()
{
	char *mem_addr;
	int shmid = 32769;
	mem_addr = shmat (shmid, 0, 1);
	if (NULL == mem_addr)
	{
		perror ("copy mem failed:");
		return -1;
	}

	printf ("%s\n", mem_addr);
	shmdt (mem_addr);
	return 0;
}
