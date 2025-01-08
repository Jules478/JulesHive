/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:50:55 by mpierce           #+#    #+#             */
/*   Updated: 2024/11/12 12:41:22 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*sub;

	i = 0;
	if (!s)
		return (NULL);
	sub = malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		start = ft_strlen(s);
	while (s[start] && len--)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = 0;
	return (sub);
}
