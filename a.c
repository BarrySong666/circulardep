#define _GNU_SOURCE 
#include <sys/time.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <dlfcn.h> 

void helperinit(void) __attribute__((constructor)); 

void (*b_call_a)(void);

void helperinit(void) 
{
	printf("a lib contrustor\n");

	void (*func)(void);
	void *handle = dlopen ("./b.so", RTLD_LAZY);
	if (!handle) {
		exit(1);
	}

        char *error;
	func = dlsym(handle, "b_ext_func");
	b_call_a = dlsym(handle, "b_call_a");
	func();
	dlclose(handle);
}

void a_ext_func(void)
{
	printf("a ext func\n");
	//b_call_a();
}
