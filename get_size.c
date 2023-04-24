#include "main.h"

/**
 * get_size - this Calculates the size to cast the argument
 * @format: Format string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int serr_i = *i + 1;
	int size = 0;

	if (format[serr_i] == 'l')
		size = LONG;
	else if (format[serr_i] == 'h')
		size = SHORT;

	if (size == 0)
		*i = serr_i - 1;
	else
		*i = serr_i;

	return (size);
}
