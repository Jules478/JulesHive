/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:07:23 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/06 16:45:09 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ptr_length(unsigned long int n)
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

int	ptr_write(unsigned long int n, int fail_check)
{
	if (n >= 16)
	{
		fail_check = ptr_write(n / 16, fail_check);
		if (fail_check < 0)
			return (-1);
		fail_check = ptr_write(n % 16, fail_check);
		if (fail_check < 0)
			return (-1);
	}
	else
	{
		if (n <= 9)
			fail_check = print_char((n + '0'));
		else
			fail_check = print_char((n - 10 + 'a'));
	}
	if (fail_check < 0)
		return (-1);
	return (ptr_length(n));
}

int	print_ptr(unsigned long int n)
{
	int	len;
	int	check;

	check = 0;
	if (n == 0)
		return (print_str("(nil)"));
	len = 0;
	len += print_str("0x");
	if (len < 0)
		return (-1);
	check = ptr_write(n, 1);
	if (check < 0)
		return (-1);
	len += check;
	return (len);
}
