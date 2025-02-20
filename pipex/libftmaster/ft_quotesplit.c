/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotesplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:35:56 by mpierce           #+#    #+#             */
/*   Updated: 2025/02/20 12:04:50 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcount(char const *s, char c)
{
	int	i;
	int	count;
	int	trigger;
	int	in_quotes;

	i = 0;
	count = 0;
	trigger = 0;
	in_quotes = 0;
	while (s[i])
	{
		if (s[i] == '"' || s[i] == '\'')
			in_quotes = !in_quotes;
		if (s[i] != c && trigger == 0 && !in_quotes)
		{
			trigger = 1;
			count++;
		}
		else if (s[i] == c && !in_quotes)
			trigger = 0;
		i++;
	}
	return (count);
}

static char	*makeword(const char *s, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		if (s[start] == '"' || s[start] == '\'')
			start++;
		else
		{
			word[i] = s[start];
			i++;
			start++;
		}
	}
	word[i] = 0;
	return (word);
}

static char	**arrclean(char **array, int index)
{
	if (array == NULL)
		return (NULL);
	while (index >= 0)
	{
		free(array[index]);
		index--;
	}
	free(array);
	return (NULL);
}

static char	**ft_split2(char **split, char const *s, char c, int index)
{
	size_t	i;
	size_t	j;
	int		in_quotes;

	i = 0;
	j = 0;
	in_quotes = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == '"' || s[i] == '\'')
			in_quotes = !in_quotes;
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || !s[i]) && index >= 0 && !in_quotes)
		{
			split[j] = makeword(s, index, i);
			if (split[j++] == NULL)
				return (arrclean(split, j));
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

char	**ft_quotesplit(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = malloc((wordcount(s, c) + 1) * (sizeof(char *)));
	if (!split)
		return (NULL);
	ft_split2(split, s, c, -1);
	return (split);
}
