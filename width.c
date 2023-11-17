#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @ft: Formatted string specifying the arguments.
 * @a: List index of arguments to be printed.
 * @lst: List of arguments.
 *
 * Return: The calculated width.
 */
int get_width(const char *ft, int *a, va_list lst)
{
	int c_i;
	int width = 0;

	for (c_i = *a + 1; ft[c_i] != '\0'; c_i++)
	{
		if (is_digit(ft[c_i]))
		{
			width *= 10;
			width += ft[c_i] - '0';
		}
		else if (ft[c_i] == '*')
		{
			c_i++;
			width = va_arg(lst, int);
			break;
		}
		else
			break;
	}

	*a = c_i - 1;
	return (width);
}
