/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:38:54 by mpierce           #+#    #+#             */
/*   Updated: 2024/11/12 12:47:16 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if ((!big || !little) && len == 0)
		return ((char *)(big));
	if (little[0] == '\0')
		return ((char *)(big));
	i = 0;
	while (big[i] && len > i)
	{
		j = 0;
		while (little[j] == big[i + j] && len > i + j)
		{
			if (little[j + 1] == '\0')
				return ((char *)(&big[i]));
			else
				j++;
		}
		i++;
	}
	return (NULL);
}
