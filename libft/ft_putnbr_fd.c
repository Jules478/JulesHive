/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:42:21 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/09 13:14:39 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd) // write integer to specified file descriptor
{
	if (n == -2147483648) // if integer is minimum integer write string copy to file descriptor
		write(fd, "-2147483648", 11);
	else if (n < 0) // if integer is negative write minus sign then feed positive integer back into function
	{
		ft_putchar_fd(45, fd);
		ft_putnbr_fd(n * -1, fd);
	}
	else if (n < 10 && n >= 0) // write out number when single digit
		ft_putchar_fd(n + 48, fd);
	else if (n > 9) // feed integer to function recursively to write each digit individually
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
