/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:34:11 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/09 13:09:06 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n) // copy specified amount of memory to new string
{
	char		*newdest;
	const char	*newsrc;

	if (!dest && !src) // if dest and src are null return pointer to dest
		return (dest);
	newdest = (char *)dest; // cast dest and src to character pointers
	newsrc = (char *)src;
	while (n--) // iterate backwards assigning each position of src to dest
		*newdest++ = *newsrc++;
	return (dest);
}
