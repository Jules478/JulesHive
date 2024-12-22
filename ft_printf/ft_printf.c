/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:36:56 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/09 17:59:53 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_check(va_list args, char format) // checks 
{
	int	count;

	count = 0;
	if (format == 'd' || format == 'i')
		count = print_int(va_arg(args, int));
	else if (format == 'u')
		count = print_uint(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		count = print_hex(va_arg(args, unsigned int), format);
	else if (format == 's')
		count = print_str(va_arg(args, char *));
	else if (format == 'c')
		count = print_char(va_arg(args, int));
	else if (format == 'p')
		count = print_ptr(va_arg(args, unsigned long int));
	else if (format == '%')
		count = print_prcnt();
	return (count);
}

int	print_invalid(char c, char null_check, int *invalid) // handles case of trailing %
{
	if (*invalid == 0 && null_check == 0) // if no other errors in formats given trailing % is not printed and length set to -1
		return (-1);
	*invalid = 1; // if error is not trailing, indicate we have an error and print the character as normal tracking length
	return (print_char(c));
}

int	valid_format(va_list args, const char *format, int i, int count) // checks for invalid format specifiers
{
	int	fail_check;
	int	invalid;

	invalid = 0; // set invalid count to 0 to handle trailing % sign cases
	while (format[i])
	{
		fail_check = 0;
		if (format[i] == '%')
		{
			if (ft_memchr(FORMATS, format[i + 1], ft_strlen(FORMATS))) // compare format specifier against string containing all valid format specifiers
				fail_check = format_check(args, format[i++ + 1]);
			else
				fail_check = print_invalid(format[i], format[i + 1], &invalid); // if no valid specifier is present error cases are handled here
		}
		else if (format[i] == '%' && format[i + 1] == 0) // trailing % will break the loop
			break ;
		else
			fail_check = print_char(format[i]); // print all other characters given
		if (fail_check < 0) // if any write function returns -1 function will return error value
			return (-1);
		count += fail_check;
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...) // write to standard output given arguments with variables
{
	int		count;
	va_list	args;

	count = 0;
	if (!format) // if function called with no input function exits with error value
		return (-1);
	va_start(args, format);
	count = valid_format(args, format, 0, 0);
	va_end(args);
	return (count);
}
