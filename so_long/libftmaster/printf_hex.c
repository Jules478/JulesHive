/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:18:42 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/06 16:44:35 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	hex_length(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	hex_write(unsigned int n, char format, int fail_check)
{
	if (n >= 16)
	{
		fail_check = hex_write(n / 16, format, fail_check);
		if (fail_check < 0)
			return (-1);
		fail_check = hex_write(n % 16, format, fail_check);
		if (fail_check < 0)
			return (-1);
	}
	else
	{
		if (n <= 9)
			fail_check = print_char((n + '0'));
		else
		{
			if (format == 'x')
				fail_check = print_char((n - 10 + 'a'));
			if (format == 'X')
				fail_check = print_char((n - 10 + 'A'));
		}
	}
	if (fail_check < 0)
		return (-1);
	return (hex_length(n));
}

int	print_hex(unsigned int n, char format)
{
	int	count;

	count = 0;
	if (n == 0)
		return (print_char('0'));
	count = hex_write(n, format, 1);
	return (count);
}
