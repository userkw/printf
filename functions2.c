#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * print_ptr - pthe value
 * @typp: List
 * @buff: Buffer
 * @flags: Calculates flags
 * @width: get
 * @precision: Precision
 * @size: Size
 * Return: Number
 */
int print_ptr(va_list typp, char buff[],
	int flags, int width, int precision, int size)
{
	char etsr_c = 0, pddd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long adresss;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(typp, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buff[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	adresss = (unsigned long)addrs;

	while (adresss > 0)
	{
		buff[ind--] = map_to[adresss % 16];
		adresss /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pddd = '0';
	if (flags & F_PLUS)
		etsr_c = '+', length++;
	else if (flags & F_SPACE)
		etsr_c = ' ', length++;

	ind++;

	return (write_pointer(buff, ind, length,
		width, flags, pddd, etsr_c, padd_start));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_print - printf ascii codes
 * @lst: lists of args
 * @buff: Buffer
 * @flags:  flags
 * @width: get
 * @precision: Precision
 * @size: Size
 * Return: Number
 */
int print_non_print(va_list lst, char buff[],
	int flags, int width, int precision, int size)
{
	int i = 0, offf = 0;
	char *string = va_arg(lst, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (string == NULL)
		return (write(1, "(null)", 6));

	while (string[i] != '\0')
	{
		if (is_printable(string[i]))
			buff[i + offf] = string[i];
		else
			offf += append_hexa_code(string[i], buff, i + offf);

		i++;
	}

	buff[i + offf] = '\0';

	return (write(1, buff, i + offf));
}
/************************* PRINT REVERSE *************************/
/**
 * print_rever - print reverse
 * @lst: lst of args
 * @buff: Buffer array
 * @flags: Calculates flags
 * @width: get width
 * @precision: Precision
 * @size: Size
 * Return: Numbers
 */
int print_rever(va_list lst, char buff[],
	int flags, int width, int precision, int size)
{
	char *string;
	int i, cnnt = 0;

	UNUSED(buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	string = va_arg(lst, char *);

	if (string == NULL)
	{
		UNUSED(precision);

		string = ")Null(";
	}
	for (i = 0; string[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = string[i];

		write(1, &z, 1);
		cnnt++;
	}
	return (cnnt);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13str - printa string
 * @lst: listof args
 * @buffeerr: Buffer
 * @flags: Calculatesflags
 * @width: get
 * @precision: Precision
 * @size: Size
 * Return: Numbers
 */
int print_rot13str(va_list lst, char buffeerr[],
	int flags, int width, int precision, int size)
{
	char x;
	char *string;
	unsigned int i, j;
	int cnnt = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	string = va_arg(lst, char *);
	UNUSED(buffeerr);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (string == NULL)
		string = "(AHYY)";
	for (i = 0; string[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == string[i])
			{
				x = out[j];
				write(1, &x, 1);
				cnnt++;
				break;
			}
		}
		if (!in[j])
		{
			x = string[i];
			write(1, &x, 1);
			cnnt++;
		}
	}
	return (cnnt);
}
