#define _GNU_SOURCE 
#include <sys/time.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <dlfcn.h> 

void helperinit(void) __attribute__((constructor)); 

void helperinit(void) 
{
	printf("b constuctor\n");
} 

void b_call_a(void)
{
	a_ext_func();
}

void b_ext_func(void)
{
	printf("b ext func\n");
	a_ext_func();
}
