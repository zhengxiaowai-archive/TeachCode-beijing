#include <stdio.h>
#include <string.h>

#define BUFFSIZE 1000

int main(int argc, char *argv[])
{
	char str[BUFFSIZE];
	memset(str, 0, sizeof(str));//bzero
	return 0;
}
