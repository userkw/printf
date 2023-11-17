#include "main.h"

/**
 * get_precision - Calculates the precision
 * @ft: Formatted string specifying the arguments
 * @a: List index of arguments
 * @lst: List of arguments
 *
 * Return: The calculated precision
 */
int get_precision(const char *ft, int *a, va_list lst)
{
	int c_i = *a + 1;
	int prcsion = -1;

	if (ft[c_i] != '.')
		return (prcsion);

	prcsion = 0;

	for (c_i += 1; ft[c_i] != '\0'; c_i++)
	{
		if (is_digit(ft[c_i]))
		{
			prcsion *= 10;
			prcsion += ft[c_i] - '0';
		}
		else if (ft[c_i] == '*')
		{
			c_i++;
			prcsion = va_arg(lst, int);
			break;
		}
		else
			break;
	}

	*a = c_i - 1;
	return (prcsion);
}
