#include <stdio.h>
#include  "config.h"

void main(void)
{
	int var;
	
	var = CMD; 
	printf("In %s \n", __func__);
	printf("a = %d \n", var);
	
	a();
}
