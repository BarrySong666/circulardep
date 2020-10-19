#define _GNU_SOURCE 
#include <sys/time.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <dlfcn.h> 

void a_helperinit(void) __attribute__((constructor)); 

void (*b_call_a)(void);

void a_helperinit(void) 
{
	printf("a lib contrustor\n");
}

void a_ext_func(void)
{
	void (*func)(void);
	void *handle = dlopen ("./b.so", RTLD_LAZY);
	if (!handle) {
		exit(1);
	}

        char *error;
	func = dlsym(handle, "b_ext_func");
	b_call_a = dlsym(handle, "b_call_a");
	b_call_a();
	func();
	dlclose(handle);

	printf("a ext func\n");
}

void a_ext1(void)
{
	printf("a_ext1\n");
}
