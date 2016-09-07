#include <stdio.h>

void func(void)
{
	char *s = NULL;

	*s = 'a';
}

int main(void)
{
	func();
	return 0;
}
