/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:38:54 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/09 17:41:26 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len) // returns pointer to the position where string little appears inside string big
{
	size_t	i;
	size_t	j;

	if ((!big || !little) && len == 0) // if little or big are null and len is 0 return pointer to big
		return ((char *)(big));
	if (little[0] == '\0') // if little is empty string return pointer to big
		return ((char *)(big));
	i = 0;
	while (big[i] && len > i)
	{
		j = 0;
		while (little[j] == big[i + j] && len > i + j) // compare each position of big with the first of little
		{												// if a match is found each subsequent position of little is checked til a full match found
			if (little[j + 1] == '\0')
				return ((char *)(&big[i])); // return pointer to position in big after little appears
			else
				j++;
		}
		i++;
	}
	return (NULL); // return null if perfect match is not found
}
