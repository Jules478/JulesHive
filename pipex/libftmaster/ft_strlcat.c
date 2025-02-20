/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:31:32 by mpierce           #+#    #+#             */
/*   Updated: 2024/11/11 17:53:31 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destlen;
	size_t	space;
	size_t	i;

	destlen = 0;
	while (destlen < size && dest[destlen])
		destlen++;
	space = size - destlen;
	if (space == 0)
		return (destlen + ft_strlen(src));
	i = 0;
	while (src[i] && i < space - 1)
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = 0;
	return (destlen + ft_strlen(src));
}
