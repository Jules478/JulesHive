/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:34:11 by mpierce           #+#    #+#             */
/*   Updated: 2024/11/12 12:26:40 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*newdest;
	const char	*newsrc;

	if (!dest && !src)
		return (dest);
	newdest = (char *)dest;
	newsrc = (char *)src;
	while (n--)
		*newdest++ = *newsrc++;
	return (dest);
}
