/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:30:46 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/09 15:26:58 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c) // check string for first occurance of specified character
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)(s + i)); // return pointer to occurance of character
		else
			i++;
	}
	if (c == '\0') // if character is null terminator return pointer to end of string
		return ((char *)(s + i));
	return (NULL);
}
