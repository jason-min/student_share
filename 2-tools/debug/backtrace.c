#include <stdio.h>
#include <execinfo.h>
#include <signal.h>
#include <stdlib.h>

void func(void)
{
	char *s = NULL;

	*s = 'a';
}

void sigdump(int signo)
{
	void *array[50];
	size_t size;
	char **strings;
	size_t i;
	
	size = backtrace(array, 50);
	strings = backtrace_symbols(array, size);
	printf("Obtained %zd stack frames. \n", size);
	for (i = 0; i < size; i++)
		printf("%s \n", strings[i]);
	free(strings);
	exit(0);
}


int main(void)
{
	signal(SIGSEGV, sigdump);
	func();
	return 0;
}
