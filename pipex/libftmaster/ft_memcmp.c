/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:25:21 by mpierce           #+#    #+#             */
/*   Updated: 2024/11/12 12:27:47 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void *s1, void *s2, size_t n)
{
	unsigned char	*s1temp;
	unsigned char	*s2temp;
	size_t			i;

	s1temp = (unsigned char *)s1;
	s2temp = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((s1temp[i] == s2temp[i]) && i < n - 1)
	{
		if (s1temp[i] == s2temp[i])
			i++;
		else
			return (s1temp[i] - s2temp[i]);
	}
	return (s1temp[i] - s2temp[i]);
}
