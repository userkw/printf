#include "main.h"
/**
 * handle_print - prints an arg
 * @fmt: formatted str the args
 * @ind: index
 * @list: list of args
 * @buffer: buffer array
 * @flags: calculates active flags
 * @width: width
 * @precision: precision
 * @size: size specifier
 *
 * Return: 1 or 2
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int a, u_lens = 0, p_char = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (a = 0; fmt_types[a].fmt != '\0'; a++)
		if (fmt[*ind] == fmt_types[a].fmt)
			return (fmt_types[a].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[a].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		u_lens += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			u_lens += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		u_lens += write(1, &fmt[*ind], 1);
		return (u_lens);
	}
	return (p_char);
}
