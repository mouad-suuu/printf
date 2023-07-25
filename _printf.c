#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _putchar - Custom putchar function to write a single character to stdout.
 * 
 *
 * Return: 1 on success, -1 on error.
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * _printf - Custom printf function.
 * 
 *
 * Return: Number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;
    char *str_arg;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++; 
            switch (*format)
            {
                case 'c':
                    _putchar(va_arg(args, int));
                    printed_chars++;
                    break;

                case 's':
                    str_arg = va_arg(args, char *);
                    while (*str_arg)
                    {
                        _putchar(*str_arg);
                        printed_chars++;
                        str_arg++;
                    }
                    break;

                case '%':
                  
                    _putchar('%');
                    printed_chars++;
                    break;
                default:
                    _putchar('%');
                    printed_chars++;
                    _putchar(*format);
                    printed_chars++;
                    break;
            }
        }
        else
        {
            _putchar(*format);
            printed_chars++;
        }

        format++;
    }

    va_end(args);

    return printed_chars;
}
