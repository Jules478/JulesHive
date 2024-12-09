/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:21:48 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/09 13:10:39 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n) // set specified amount of memory to a given character
{
	char	*ptr;

	ptr = (char *) s; // cast string to character pointer
	while (n-- > 0)
	{
		*ptr++ = c; // assign each position to specified character
	}
	return (s);
}
