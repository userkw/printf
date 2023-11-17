#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_ch - prints a char
 * @typ: list a of args
 * @buff: buffer array
 * @flags: calculates flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: number of chars
 */
int print_ch(va_list typ, char buff[],
	int flags, int width, int precision, int size)
{
	char j = va_arg(typ, int);

	return (handle_write_char(j, buff, flags, width, precision, size));
}
/************************* PRINT A STRING *************************/
/**
 * print_str - prints a string
 * @typ: list a of args
 * @buff: buffer array
 * @flags: calculates flags
 * @width: width
 * @precision: precision
 * @size: sze
 * Return: number of chars
 */
int print_str(va_list typ, char buff[],
	int flags, int width, int precision, int size)
{
	int lent = 0, a;
	char *string = va_arg(typ, char *);

	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (string == NULL)
	{
		string = "(null)";
		if (precision >= 6)
			string = "      ";
	}

	while (string[lent] != '\0')
		lent++;

	if (precision >= 0 && precision < lent)
		lent = precision;

	if (width > lent)
	{
		if (flags & F_MINUS)
		{
			write(1, &string[0], lent);
			for (a = width - lent; a > 0; a--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (a = width - lent; a > 0; a--)
				write(1, " ", 1);
			write(1, &string[0], lent);
			return (width);
		}
	}

	return (write(1, string, lent));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_perc - prints a percent
 * @typ: list
 * @buff: Buffer
 * @flags: calculatesflags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: Number of chars
 */
int print_perc(va_list typ, char buff[],
	int flags, int width, int precision, int size)
{
	UNUSED(typ);
	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_i - print int
 * @typ: lista of arguments
 * @buff: buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_i(va_list typ, char buff[],
	int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(typ, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buff[a--] = '0';

	buff[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buff[a--] = (num % 10) + '0';
		num /= 10;
	}

	a++;

	return (write_number(is_negative, a, buff, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_bin - Prints an unsigned binary number
 * @typp: List of arguments
 * @buff: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width specification
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed.
 */
int print_bin(va_list typp, char buff[],
	int flags, int width, int precision, int size)
{
	unsigned int num, mask, i, sum;
	unsigned int binary[32];
	int count;

	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	num = va_arg(typp, unsigned int);
	mask = 2147483648; /* (2 ^ 31) */
	binary[0] = num / mask;
	for (i = 1; i < 32; i++)
	{
		mask /= 2;
		binary[i] = (num / mask) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += binary[i];
		if (sum || i == 31)
		{
			char z = '0' + binary[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
