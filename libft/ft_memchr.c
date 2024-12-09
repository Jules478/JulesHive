/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:18:15 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/09 13:03:31 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n) // check specified amount of memory if string matches a specified character
{
	char	*temp;
	int		i;

	temp = (char *)s; // cast string to character pointer
	i = 0;
	while (n--) // iterate backwards from specified index
	{
		if (temp[i] == c)
			return (&temp[i]); // return memory address of the match
		i++;
	}
	return (NULL);
}
