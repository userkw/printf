#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_uns - prints an unsigned nbr
 * @typ: list a of args
 * @buff: buffer array
 * @flags:  calculates flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: Number of chars
 */
int print_uns(va_list typ, char buff[],
	int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int num = va_arg(typ, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buff[a--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buff[a--] = (num % 10) + '0';
		num /= 10;
	}

	a++;

	return (write_unsgnd(0, a, buff, flags, width, precision, size));
}
/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_oc - prints an unsigned number
 * @typ: Lista of ar
 * @buff: buffr array
 * @flags: calcul flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: Number
 */
int print_oc(va_list typ, char buff[],
	int flags, int width, int precision, int size)
{

	int a = BUFF_SIZE - 2;
	unsigned long int nm = va_arg(typ, unsigned long int);
	unsigned long int init_num = nm;

	UNUSED(width);

	nm = convert_size_unsgnd(nm, size);

	if (nm == 0)
		buff[a--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (nm > 0)
	{
		buff[a--] = (nm % 8) + '0';
		nm /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buff[a--] = '0';

	a++;

	return (write_unsgnd(0, a, buff, flags, width, precision, size));
}
/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints an unsigned number
 * @typ: Lista of args
 * @buff: Buffer array
 * @flags:  Calculates
 * @width: get
 * @precision: Precision
 * @size: Size
 * Return: Numbe
 */
int print_hexadecimal(va_list typ, char buff[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(typ, "0123456789abcdef", buff,
		flags, 'x', width, precision, size));
}
/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_up - Prints an unsigned numberr
 * @typ: Lista of ar
 * @buff: Buffer
 * @flags:  Calculates
 * @width: get
 * @precision: Precision
 * @size: Size
 * Return: Number
 */
int print_hexa_up(va_list typ, char buff[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(typ, "0123456789ABCDEF", buff,
		flags, 'X', width, precision, size));
}
/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - printa hexadecima
 * @typ: lst of arguments
 * @m_to: ary of values
 * @buff: Buffer
 * @flags:  Calculate
 * @flag_ch: Calculates flags
 * @width: get
 * @precision: Precision
 * @size: Size
 * Return: Number
 */
int print_hexa(va_list typ, char m_to[], char buff[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int aa = BUFF_SIZE - 2;
	unsigned long int num = va_arg(typ, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buff[aa--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buff[aa--] = m_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buff[aa--] = flag_ch;
		buff[aa--] = '0';
	}

	aa++;

	return (write_unsgnd(0, aa, buff, flags, width, precision, size));
}
