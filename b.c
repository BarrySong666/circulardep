#define _GNU_SOURCE 
#include <sys/time.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <dlfcn.h> 

void b_helperinit(void) __attribute__((constructor)); 

void b_helperinit(void) 
{
	printf("b constuctor\n");
} 

void b_call_a(void)
{
	a_ext1();
}

void b_ext_func(void)
{
	printf("b ext func\n");
	//a_ext_func();
}
