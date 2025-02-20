/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:50:29 by mpierce           #+#    #+#             */
/*   Updated: 2025/02/18 15:03:24 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	next_line(char	*buffer)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE && buffer[i])
	{
		i++;
		if (buffer[i - 1] == '\n')
			break ;
	}
	return (i);
}

static char	*update(char *line, char *buffer)
{
	char	*str;
	size_t	line_len;
	size_t	buffer_len;
	size_t	total_len;

	buffer_len = next_line(buffer);
	line_len = 0;
	if (line)
		line_len = ft_strlen(line);
	total_len = line_len + buffer_len;
	str = malloc((total_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memmove(str, line, line_len);
	ft_memmove(str + line_len, buffer, buffer_len);
	ft_bzero(buffer, buffer_len);
	str[total_len] = 0;
	ft_memmove(buffer, buffer + buffer_len, BUFFER_SIZE - buffer_len);
	ft_bzero(buffer + BUFFER_SIZE - buffer_len, buffer_len);
	free(line);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buffer[OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			read_len;

	line = NULL;
	while (1)
	{
		if (!buffer[fd][0])
		{
			read_len = read(fd, buffer[fd], BUFFER_SIZE);
			if (read_len < 0)
				break ;
			if (!buffer[fd][0])
				return (line);
			buffer[fd][read_len] = 0;
		}
		line = update(line, buffer[fd]);
		if (!line)
			return (GNL_ERROR);
		if (line[ft_strlen(line) - 1] == '\n')
			return (line);
	}
	free(line);
	return (NULL);
}
