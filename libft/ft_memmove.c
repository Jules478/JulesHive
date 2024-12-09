/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:36:39 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/09 13:10:01 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n) // duplicate memory protecting against overwrite
{
	char		*newdest;
	const char	*newsrc;
	int			i;

	if (!dest && !src) // if dest and src are both null return pointer to dest
		return (dest);
	newdest = (char *)dest; // cast both dest and src to character pointer
	newsrc = (char *)src;
	i = 0;
	if (dest > src) // if the memory address of dest is larger than src iterate backwards to prevent memory loss
	{
		while (n--)
			newdest[n] = newsrc[n];
		return (dest);
	}
	else // if memory address is small iterate forwards to protect against loss
	{
		while (n--)
		{
			newdest[i] = newsrc[i];
			i++;
		}
		return (dest);
	}
}
