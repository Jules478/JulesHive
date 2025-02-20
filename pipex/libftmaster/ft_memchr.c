/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:18:15 by mpierce           #+#    #+#             */
/*   Updated: 2024/11/12 13:29:33 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*temp;
	int		i;

	temp = (char *)s;
	i = 0;
	while (n--)
	{
		if (temp[i] == c)
			return (&temp[i]);
		i++;
	}
	return (NULL);
}
