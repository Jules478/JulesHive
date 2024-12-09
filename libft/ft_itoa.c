/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:52:29 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/09 12:30:06 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n) // calculate length of integer
{
	int	len;

	len = 1;
	if (n < 0) // convert to positive and account for minus sign
	{
		n *= -1;
		len++;
	}
	while (n > 9) // increments count while dividing by 10
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n) // convert integer to string
{
	int		i;
	char	*str;
	int		result;

	if (n == INT_MIN) // check for minimum integer to protect against underflow
		return (ft_strdup("-2147483648"));
	i = intlen(n);
	result = n;
	str = malloc((i + 1) * sizeof(char)); 
	if (!str) // malloc fail check
		return (NULL);
	str[i] = 0; // null terminal string
	if (n < 0)
		result *= -1; // prepare result for negative conversion
	while (i--) // increment down while adding remainders to string adding characters in reverse
	{
		str[i] = (result % 10) + 48;
		result /= 10;
	}
	if (n < 0) // add minus sign for negative integer, we accounted for the space needed for this in intlen
		str[0] = 45;
	return (str);
}
