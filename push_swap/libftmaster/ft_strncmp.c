/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:52:14 by mpierce           #+#    #+#             */
/*   Updated: 2024/11/08 16:15:10 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1a;
	unsigned char	*s2a;

	i = 0;
	s1a = (unsigned char *)s1;
	s2a = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((s1a[i] == s2a[i]) && (s1a[i] || s2a[i]) && i < n - 1)
	{
		if (s1a[i] == s2a[i])
			i++;
		else
			return (s1a[i] - s2a[i]);
	}
	return (s1a[i] - s2a[i]);
}
