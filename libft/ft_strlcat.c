/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:31:32 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/09 16:24:44 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size) // concatenate specified about of bytes of string src to the end of string dest
{
	size_t	destlen;
	size_t	space;
	size_t	i;

	destlen = 0;
	while (destlen < size && dest[destlen]) // calculate starting position of concatenation by either size or length of string dest
		destlen++;
	space = size - destlen;
	if (space == 0) // if size was same as destlen return length of string that would be created without concatenating the strings
		return (destlen + ft_strlen(src));
	i = 0;
	while (src[i] && i < space - 1) // concatenate the strings up to to the remaining space is depleted
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = 0;
	return (destlen + ft_strlen(src));
}
