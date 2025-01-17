/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:50:29 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/06 16:37:07 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*freeresult(char *buffer1, char *buffer2)
{
	char	*tempbuffer;

	tempbuffer = ft_strjoin(buffer1, buffer2);
	free(buffer1);
	return (tempbuffer);
}

char	*read_file(int fd, char *buffer)
{
	char	*result;
	int		bytes;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	result = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!result)
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, result, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(result);
			free(buffer);
			return (NULL);
		}
		result[bytes] = 0;
		buffer = freeresult(buffer, result);
		if (ft_strchr(result, '\n'))
			break ;
	}
	free(result);
	return (buffer);
}

char	*next_line(char *buffer)
{
	char	*newline;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	newline = ft_calloc((i + 2), sizeof(char));
	if (!newline)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		newline[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		newline[i] = '\n';
	newline[i + 1] = 0;
	return (newline);
}

char	*update_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*newbuffer;

	i = 0;
	j = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	newbuffer = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	i++;
	while (buffer[i])
	{
		newbuffer[j] = buffer[i];
		i++;
		j++;
	}
	free(buffer);
	return (newbuffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*nextline;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	buffer[fd] = read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	nextline = next_line(buffer[fd]);
	buffer[fd] = update_buffer(buffer[fd]);
	return (nextline);
}
