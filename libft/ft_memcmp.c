/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:25:21 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/09 13:06:07 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void *s1, void *s2, size_t n) // compare specified amount of memory for match between two strings
{
	unsigned char	*s1temp;
	unsigned char	*s2temp;
	size_t			i;

	s1temp = (unsigned char *)s1; // cast both strings to character pointers
	s2temp = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((s1temp[i] == s2temp[i]) && i < n - 1) // iterate while within scope and strings continue to match
	{
		if (s1temp[i] == s2temp[i])
			i++;
		else
			return (s1temp[i] - s2temp[i]); // return difference between the two strings
	}
	return (s1temp[i] - s2temp[i]);
}
