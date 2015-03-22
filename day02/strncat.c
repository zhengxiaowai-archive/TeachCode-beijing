#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

	char str1[20] = "Hello";
	char str2[20] = "World";

	strncat(str1,str2,2);

	printf("%s\n", str1);
	return 0;
}
