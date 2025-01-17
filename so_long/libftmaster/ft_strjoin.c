/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:09:30 by mpierce           #+#    #+#             */
/*   Updated: 2024/11/12 14:10:03 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	totallen;
	char	*newstr;

	if (!s1 || !s2)
		return (NULL);
	totallen = ((ft_strlen(s1) + ft_strlen(s2)) + 1);
	newstr = malloc(totallen);
	if (newstr == NULL)
		return (NULL);
	while (*s1 != 0)
	{
		*newstr = *s1;
		newstr++;
		s1++;
	}
	while (*s2 != 0)
	{
		*newstr = *s2;
		newstr++;
		s2++;
	}
	*newstr = 0;
	return (newstr - (totallen - 1));
}
