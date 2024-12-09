/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:07:36 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/09 12:16:00 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr) // convert string to integer
{
	int	i;
	int	num;
	int	neg;

	i = 0;
	num = 0;
	neg = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13)) // ignore spaces
		i++;
	if (nptr[i] == 45) // prepare final result to become negative
	{
		neg *= -1;
		i++;
	}
	else if (nptr[i] == 43) // ignore plus sign
		i++;
	while ((nptr[i] >= 48 && nptr[i] <= 57) && nptr[i]) // while position is integer
	{
		num = num * 10 + (nptr[i] - 48); // convert character to digit and move across one place
		i++;
	}
	return (num * neg);
}
