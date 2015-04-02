#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, char *argv[])
{
	int shmid = shmget(IPC_PRIVATE, 1024, 00666);
	if(shmid < 0)
	{
		return -1;
	}
	return 0;
}
