/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:48:04 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/09 15:23:08 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcount(char const *s, char c) // counts number of elements that will be needed
{
	int	i;
	int	count;
	int	trigger;

	i = 0;
	count = 0;
	trigger = 0;
	while (s[i])
	{
		if (s[i] != c && trigger == 0) // while the position is not the deliminator and a word is not being read
		{
			trigger = 1; // set trigger to 1 to indicate we are now reading a word
			count++;
		}
		else if (s[i] == c) // when a deliminator is found we reset trigger ready for the next word
			trigger = 0;
		i++;
	}
	return (count);
}

static char	*makeword(const char *s, int start, int end) // assign portion of string to array
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = 0;
	return (word);
}

static int	arrclean(char **array, int index) // free each element of array then array itself
{
	if (array == NULL)
		return (0);
	while (index >= 0)
	{
		free(array[index]);
		index--;
	}
	free(array);
	return (0);
}

static char	**ft_split2(char **split, char const *s, char c, int index) // helper function to do the meat of the function
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i <= ft_strlen(s)) 
	{
		if (s[i] != c && index < 0) // if the position is not the deliminator and we are not currently reading a word
			index = i; // set index to the starting position of the word
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0) // if we have reached a delimitator or the end of a string and are currently reading a word
		{
			split[j] = makeword(s, index, i); // assign result of makeword to an element of the array
			if (split[j] == NULL) // if makeword fails we free the entire array
			{
				arrclean(split, j);
				return (0);
			}
			j++;
			index = -1; // reset index ready for next word start
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

char	**ft_split(char const *s, char c) // convert string into array separating each element of the array by a given deliminator
{
	char	**split;

	if (!s) // if string is null return null
		return (NULL);
	split = malloc((wordcount(s, c) + 1) * (sizeof(char *))); // allocate space for array
	if (!split)
		return (NULL);
	ft_split2(split, s, c, -1); // feed all relevant variables to split2 along with index to keep split2 length below 25 lines
	return (split);
}
