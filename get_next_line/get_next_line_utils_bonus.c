/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:04:49 by mpierce           #+#    #+#             */
/*   Updated: 2024/11/26 16:29:04 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)(s + i));
		else
			i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	totallen;
	char	*newstr;
	char	*nnewstr;

	if (!s1 || !s2)
		return (NULL);
	totallen = ((ft_strlen(s1) + ft_strlen(s2)) + 1);
	newstr = ft_calloc(totallen, sizeof(char));
	if (newstr == NULL)
		return (NULL);
	nnewstr = newstr;
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
	return (nnewstr);
}

void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n-- > 0)
		*ptr++ = c;
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	memory;
	void	*ptr;

	if (!size || !nmemb)
		return (NULL);
	if (SIZE_MAX / size < nmemb)
		return (0);
	memory = size * nmemb;
	ptr = malloc(memory);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, memory);
	return (ptr);
}
