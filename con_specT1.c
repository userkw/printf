#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list list_v;
    int cnt = 0;
    char *strr;

    va_start(list_v, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
		case 'd':
                    cnt += _putchar(va_arg(list_v, int));
                    break;

		case 'i':
                    cnt += _putchar(va_arg(list_v, int));
                    break;

                case 'c':
                    cnt += _putchar(va_arg(list_v, int));
                    break;
                case 's':
                    strr = va_arg(list_v, char *);
                    if (strr == NULL)
                        strr = "(null)";
                    while (*strr)
                    {
                        cnt += _putchar(*strr);
                        strr++;
                    }
                    break;
                case '%':
                    cnt += _putchar('%');
                    break;
                default:
                    cnt += _putchar('%');
                    cnt += _putchar(*format);
                    break;
            }
        }
        else
        {
            cnt += _putchar(*format);
        }
        format++;
    }

    va_end(list_v);

    return cnt;
}
