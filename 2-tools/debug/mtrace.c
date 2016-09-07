#include <stdio.h>
#include <stdlib.h>
#include <mcheck.h>

void main(void)
{
	char *p = NULL;

	mtrace();
	p = (char*)malloc(10);
	muntrace();
}
