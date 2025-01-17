/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:36:56 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/06 16:44:37 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	format_check(va_list args, char format)
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

int	print_invalid(char c, char null_check, int *invalid)
{
	if (*invalid == 0 && null_check == 0)
		return (-1);
	*invalid = 1;
	return (print_char(c));
}

int	valid_format(va_list args, const char *format, int i, int count)
{
	int	fail_check;
	int	invalid;

	invalid = 0;
	while (format[i])
	{
		fail_check = 0;
		if (format[i] == '%')
		{
			if (ft_memchr(FORMATS, format[i + 1], ft_strlen(FORMATS)))
				fail_check = format_check(args, format[i++ + 1]);
			else
				fail_check = print_invalid(format[i], format[i + 1], &invalid);
		}
		else if (format[i] == '%' && format[i + 1] == 0)
			break ;
		else
			fail_check = print_char(format[i]);
		if (fail_check < 0)
			return (-1);
		count += fail_check;
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	count = valid_format(args, format, 0, 0);
	va_end(args);
	return (count);
}
