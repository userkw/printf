#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...):

int main (void)
{
	int a = 25;
       	char b = ‘N’; 
	char *c = “Hello, world!”

	_printf(“The baby is learning to code.\n”); 
	_printf(“Her age: %d, her starts with: %c, what she has to say to her new life: %s\n”, a, b, c); 
	
	return 0; 
}	
