#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
        va_list args;
        int count_char = 0;

        if (*format != NULL && *format != '%'0)
                        puts(*format);
                        count_char++;

        va_start(args, format);

        while (*format)
                puts(*format)
                count_char++;

        if (*format == '%')
        {
                        if (*format == '\0')
                                return (-1);

                        else (*format == 'c')
                                char c = va_arg(args, int);

                        else (*format == 's')
                                char *str = va_arg(args, char*);

                        else (*format == 'i')
                                int i = va_arg(args, int);

                        else (*format == 'd')
                                int d = va_arg(args, int);
        }
        va_end(args);
        return count_char;
}
"Self_practice" 38L, 624C                                                                                                                     1,1           Top
