/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:36:39 by mpierce           #+#    #+#             */
/*   Updated: 2024/11/12 12:25:52 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*newdest;
	const char	*newsrc;
	int			i;

	if (!dest && !src)
		return (dest);
	newdest = (char *)dest;
	newsrc = (char *)src;
	i = 0;
	if (dest > src)
	{
		while (n--)
			newdest[n] = newsrc[n];
		return (dest);
	}
	else
	{
		while (n--)
		{
			newdest[i] = newsrc[i];
			i++;
		}
		return (dest);
	}
}
