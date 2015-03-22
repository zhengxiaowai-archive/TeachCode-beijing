#include <stdio.h>
#include <dlfcn.h>

int main(int argc, char *argv[])
{
	void *phandle = dlopen("./libadd.so.1", RTLD_LAZY);
	if(NULL == phandle)
	{
		printf("failed load library:%s\n", dlerror());
		return -1;
	}

	int (* add)(int a, int b) = dlsym(phandle, "add");
	if(NULL == add)
	{
		printf("failed load library:%s\n", dlerror());
		return -1;
	}

	printf("sum = %d", add(2,3));
	dlclose(phandle);
	return 0;
}
