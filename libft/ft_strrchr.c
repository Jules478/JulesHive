/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:59:09 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/09 17:42:31 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c) // check string for final occurance of specified character
{
	int	i;

	i = 0;
	while (s[i]) // iterate to the end of the string
		i++;
	if (c == '\0') // if character is null terminator then return pointer to end of string
		return ((char *)(s + i));
	while (i >= 0)
	{
		if (s[i] == c) // iterate backwards until match is found
			return ((char *)(s + i));
		else
			i--;
	}
	return (NULL);
}
