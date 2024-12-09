/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:52:14 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/09 17:38:39 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, const char *s2, size_t n) // compare specified amount of bytes of two strings
{
	size_t			i;
	unsigned char	*s1a;
	unsigned char	*s2a;

	i = 0;
	s1a = (unsigned char *)s1; // cast both strings to character pointer
	s2a = (unsigned char *)s2;
	if (n == 0) // if n is 0 no bytes are read
		return (0);
	while ((s1a[i] == s2a[i]) && (s1a[i] || s2a[i]) && i < n - 1) // while the strings match and within scope
	{
		if (s1a[i] == s2a[i])
			i++;
		else
			return (s1a[i] - s2a[i]);
	}
	return (s1a[i] - s2a[i]);
}
