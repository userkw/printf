#include "main.h"

void print_buffer(char buffer[], int *bf_index);

/**
 * _printf - Printf function
 * @format: format
 * Return: Printed chars
 */
int _printf(const char *format, ...)
{
	int i, prted = 0, p_chars = 0;
	int flags, width, precision, size, bf_index = 0;
	va_list lst;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(lst, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[bf_index++] = format[i];
			if (bf_index == BUFF_SIZE)
				print_buffer(buffer, &bf_index);
			print_chars++;
		}
		else
		{
			print_buffer(buffer, &bf_index);
			flags = get_flags(format, &i);
			width = get_width(format, &i, lst);
			precision = get_precision(format, &i, lst);
			size = get_size(format, &i);
			++i;
			prted = handle_print(format, &i, lst, buffer,
					       flags, width, precision, size);
			if (prted == -1)
				return (-1);
			p_chars += prted;
		}
	}

	print_buffer(buffer, &bf_index);

	va_end(lst);

	return (p_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @bf_index: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *bf_index)
{
	if (*bf_index > 0)
		write(1, &buffer[0], *bf_index);

	*bf_index = 0;
}
