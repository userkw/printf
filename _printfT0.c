#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...);
{
	va_list args;
	int count_char = 0;
	char *p, *s, buffer[10];
	int n;

	if (format == NULL)
 	return -1;

	va_start(args, format);
	p = format;

	while (*p != '\0')

	{
	if (*p != '%')
	{
	putchar(*p);
	count_char++;

	}
	else
	{
	p++;
		if (*p == '\0')
		break;

	switch (*p)
	{
        case 'c':
		n = va_arg(args, int);
		putchar(n);
		count_char++;
		break;

	case 's':
		s = va_arg(args, char*);
		puts(s);
		count_char += strlen(s);
		break;

	case 'i':
	case 'd':
		n = va_arg(args, int);
		if (n < 0)
	{
		putchar('-');
		count_char++;
		n = -n;
	}

	itoa(n, buffer, 10);
	puts(buffer);
	count_char += strlen(buffer);
	break;

        default:
	putchar('%');
	putchar(*p);
	count_char += 2;
	break;
      }
    }
	p++;
  }

	va_end(args);
	return count_char;
}

