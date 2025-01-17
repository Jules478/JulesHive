/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:07:36 by mpierce           #+#    #+#             */
/*   Updated: 2024/11/08 15:05:31 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	i;
	int	num;
	int	neg;

	i = 0;
	num = 0;
	neg = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == 45)
	{
		neg *= -1;
		i++;
	}
	else if (nptr[i] == 43)
		i++;
	while ((nptr[i] >= 48 && nptr[i] <= 57) && nptr[i])
	{
		num = num * 10 + (nptr[i] - 48);
		i++;
	}
	return (num * neg);
}
