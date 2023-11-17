#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * handle_write_char - Print a character to the buffer.
 * @cyp: The character to be printed.
 * @buff: Buffer array to handle the print operation.
 * @flags: Active flags used for formatting.
 * @width: Width specification for formatting.
 * @precision: Precision specifier for formatting.
 * @size: Size specifier for formatting.
 *
 * Return: The number of characters printed.
 */
int handle_write_char(char cyp, char buff[],
	int flags, int width, int precision, int size)
{ /* char is stored at left and padding at buffer's right */
	int a = 0;
	char pdd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		pdd = '0';

	buff[a++] = cyp;
	buff[a] = '\0';

	if (width > 1)
	{
		buff[BUFF_SIZE - 1] = '\0';
		for (a = 0; a < width - 1; a++)
			buff[BUFF_SIZE - a - 2] = pdd;

		if (flags & F_MINUS)
			return (write(1, &buff[0], 1) +
					write(1, &buff[BUFF_SIZE - a - 1], width - 1));
		else
			return (write(1, &buff[BUFF_SIZE - a - 1], width - 1) +
					write(1, &buff[0], 1));
	}

	return (write(1, &buff[0], 1));
}
/************************* WRITE NUMBER *************************/
/**
 * write_nbr - Prints a number to the buffer.
 * @is_n: Signifies whether the number is negative.
 * @index: Index of characters.
 * @buff: Buffer array for print handling.
 * @flags: Active flags for calculation.
 * @width: Width specification.
 * @precision: Precision specifier.
 * @size: Size specifier.
 *
 * Return: Number of characters printed.
 */
int write_nbr(int is_n, int index, char buff[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - index - 1;
	char pdd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pdd = '0';
	if (is_n)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(index, buff, flags, width, precision,
		length, pdd, extra_ch));
}

/**
 * write_num - write a number using a buff
 * @index: index at which the number starts
 * @buff: Buffer
 * @flags: Flags
 * @width: width
 * @prec: Precision
 * @length: Number
 * @padd: Padding
 * @extra_c: Extra
 *
 * Return: Number of printed
 */
int write_num(int index, char buff[],
	int flags, int width, int prec,
	int length, char padd, char extra_c)
{
	int i, p_st = 1;

	if (prec == 0 && index == BUFF_SIZE - 2 && buff[index] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && index == BUFF_SIZE - 2 && buff[index] == '0')
		buff[index] = padd = ' '; /* width is displayed with padding ' ' */
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buff[--index] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buff[i] = padd;
		buff[i] = '\0';
		if (flags & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
		{
			if (extra_c)
				buff[--index] = extra_c;
			return (write(1, &buff[index], length) + write(1, &buff[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')/* extra char to left of buff */
		{
			if (extra_c)
				buff[--index] = extra_c;
			return (write(1, &buff[1], i - 1) + write(1, &buff[index], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buff[--p_st] = extra_c;
			return (write(1, &buff[p_st], i - p_st) +
				write(1, &buff[index], length - (1 - p_st)));
		}
	}
	if (extra_c)
		buff[--index] = extra_c;
	return (write(1, &buff[index], length));
}
/**
 * write_unsgnd - Writes an unsigned
 * @is_n: Number ind if the num is neg
 * @index: Index at which the number
 * @buff: Array
 * @flags: Flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 *
 * Return: Number
 */
int write_unsgnd(int is_n, int index,
	char buff[],
	int flags, int width, int precision, int size)
{
	/* The number is stored at the buff's right and starts at position i */
	int length = BUFF_SIZE - index - 1, i = 0;
	char pdd = ' ';

	UNUSED(is_n);
	UNUSED(size);

	if (precision == 0 && index == BUFF_SIZE - 2 && buff[index] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (precision > 0 && precision < length)
		pdd = ' ';

	while (precision > length)
	{
		buff[--index] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pdd = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buff[i] = pdd;

		buff[i] = '\0';

		if (flags & F_MINUS) /* Assign extra char to the left of buffer [buffer>padd] */
		{
			return (write(1, &buff[index], length) + write(1, &buff[0], i));
		}
		else /* Assign extra char to the left of padding [padd>buffer] */
		{
			return (write(1, &buff[0], i) + write(1, &buff[index], length));
		}
	}

	return (write(1, &buff[index], length));
}
/**
 * write_pointer - Write a memory
 * @buff: Arrays of chars
 * @index: Index at which the number
 * @lent: Length
 * @width: Width
 * @flags: Flags
 * @pdd: Char
 * @ex_c: Char
 * @p_start: Index
 *
 * Return: Numbe
 */
int write_pointer(char buff[], int index, int lent,
	int width, int flags, char pdd, char ex_c, int p_start)
{
	int i;

	if (width > lent)
	{
		for (i = 3; i < width - lent + 3; i++)
			buff[i] = pdd;
		buff[i] = '\0';
		if (flags & F_MINUS && pdd == ' ')/* Asign extra char to left of buff */
		{
			buff[--index] = 'x';
			buff[--index] = '0';
			if (ex_c)
				buff[--index] = ex_c;
			return (write(1, &buff[index], lent) + write(1, &buff[3], i - 3));
		}
		else if (!(flags & F_MINUS) && pdd == ' ')/* extra char to left of buff */
		{
			buff[--index] = 'x';
			buff[--index] = '0';
			if (ex_c)
				buff[--index] = ex_c;
			return (write(1, &buff[3], i - 3) + write(1, &buff[index], lent));
		}
		else if (!(flags & F_MINUS) && pdd == '0')/* extra char to left of padd */
		{
			if (ex_c)
				buff[--p_start] = ex_c;
			buff[1] = '0';
			buff[2] = 'x';
			return (write(1, &buff[p_start], i - p_start) +
				write(1, &buff[index], lent - (1 - p_start) - 2));
		}
	}
	buff[--index] = 'x';
	buff[--index] = '0';
	if (ex_c)
		buff[--index] = ex_c;
	return (write(1, &buff[index], BUFF_SIZE - index - 1));
}
