#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int serr_i = *i + 1;
	int precision = -1;

	if (format[serr_i] != '.')
		return (precision);

	precision = 0;

	for (serr_i += 1; format[serr_i] != '\0'; serr_i++)
	{
		if (is_digit(format[serr_i]))
		{
			precision *= 10;
			precision += format[serr_i] - '0';
		}
		else if (format[serr_i] == '*')
		{
			serr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = serr_i - 1;

	return (precision);
}
