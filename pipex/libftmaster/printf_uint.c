/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:01:52 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/06 16:46:09 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	uintlen(unsigned int n)
{
	int	len;

	len = 1;
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_unsignitoa(unsigned int n, int len)
{
	char				*str;
	unsigned int		result;

	result = n;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = 0;
	while (len--)
	{
		str[len] = (result % 10) + 48;
		result /= 10;
	}
	return (str);
}

int	print_uint(unsigned int n)
{
	char	*number;
	int		count;

	count = 0;
	if (n == 0)
		return (write(1, "0", 1));
	number = ft_unsignitoa(n, uintlen(n));
	count = print_str(number);
	free(number);
	return (count);
}
