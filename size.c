#include "main.h"

/**
 * get_size - clculates the size
 * @ft: formatted str the args
 * @a: list index of arguments
 *
 * Return: ssize
 */
int get_size(const char *ft, int *a)
{
	int c_i = *a + 1;
	int sze = 0;

	if (ft[c_i] == 'l')
		sze = S_LONG;
	else if (ft[c_i] == 'h')
		sze = S_SHORT;

	if (sze == 0)
		*a = c_i - 1;
	else
		*a = c_i;

	return (sze);
}
