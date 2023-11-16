#include <stdio.h>
#include "main.h"

int _printf(const char *format, ...)
{
	va_list args;
	int count_char = 0;

	if (*format != NULL && *format != '%'0)
			putchar(*format);
			count_char++;

	va_start(args, format);

	for (i = 0; i < *format; i++)
		putchar(*format)
		count_char++;

	if (*format == '%')
	{
			if (*format == '\0')
				break;
			
			else (*format == 'c')
				char c = va_arg(args, int);

			else (*format == 's')
				char *str = va_arg(args, char*);

			else (*format == 'i')
				int i = va_arg(args, int);

			else (*format == 'd')
				int d = va_arg(args, int);
	}
	va_end(args);
	return count_char;
}
