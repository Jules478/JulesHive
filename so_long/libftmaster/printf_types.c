/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:33:37 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/06 16:45:34 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_str(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		if (print_char(str[i]) < 0)
			return (-1);
		count++;
		i++;
	}
	return (count);
}

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_prcnt(void)
{
	return (write(1, "%", 1));
}

int	print_int(int n)
{
	int		length;
	char	*number;

	length = 0;
	number = ft_itoa(n);
	length = print_str(number);
	free(number);
	return (length);
}
