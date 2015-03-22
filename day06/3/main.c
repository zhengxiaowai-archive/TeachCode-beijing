#include <stdio.h>
#include "add/add.h"
#include "sub/sub.h"

int main()
{
	printf("3 + 2 = %d\n", add_int(3,2));
	printf("3.1 + 2.2 = %f\n", add_float(3.1,2.2));
	printf("3 - 2 = %d\n", sub_int(3,2));
	printf("3.1 - 2.2 = %f\n", sub_float(3.1,2.2));
	return 0;
}
