#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	char *some_mem;

	some_mem = (char *)malloc(20);
	printf("Malloc some memory! \n");
	return 0;
}
