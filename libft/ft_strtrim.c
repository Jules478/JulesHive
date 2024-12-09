/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:04:09 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/09 17:45:25 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set) // remove characters specified in set from the beginning and end of string
{
	int		start;
	int		end;
	char	*trimmed;

	if (!s1) // if string is null we return null
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) && start <= end) // while ft_strchr returns valid pointers and start is not equal or greater to the length of the string
		start++; // increment start of string to extract
	if (start > end) // if start exceeds the end of the string we duplicate the entire string
		return (ft_strdup(s1 + end + 1));
	while (ft_strchr(set, s1[end]) && end >= 0) // do the same but from the end of the string
		end--;
	trimmed = ft_calloc(end - start + 2, sizeof(char)); // allocate memory of the size of the string minus trimmed characters
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, &s1[start], end - start + 2); // copy string to newly allocated memory
	return (trimmed);
}
