#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

int main(int argc, char **argv)
{
	void (*func)(void);
	void *handle = dlopen ("./liba.so", RTLD_LAZY);
	if (!handle) {
		exit(1);
	}

        char *error;
	func = dlsym(handle, "a_ext_func");

	func();
	while(1);
	dlclose(handle);
}
