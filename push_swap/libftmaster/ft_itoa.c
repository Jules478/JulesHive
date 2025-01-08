/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:52:29 by mpierce           #+#    #+#             */
/*   Updated: 2024/11/12 14:14:34 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;
	int		result;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	i = intlen(n);
	result = n;
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[i] = 0;
	if (n < 0)
		result *= -1;
	while (i--)
	{
		str[i] = (result % 10) + 48;
		result /= 10;
	}
	if (n < 0)
		str[0] = 45;
	return (str);
}
