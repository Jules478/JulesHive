/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:29:50 by mpierce           #+#    #+#             */
/*   Updated: 2025/02/03 14:12:00 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	open_heredoc(t_pipex *pipex, char *lim)
{
	pipex->fd_in = (open(".temp", O_CREAT | O_EXCL | O_WRONLY, 0644));
	if (pipex->fd_in == -1)
		error_ret(pipex, "here_doc");
	heredoc_write(pipex, lim);
	close(pipex->fd_in);
	pipex->fd_in = open(".temp", O_RDONLY);
	if (pipex->fd_in == -1)
		error_ret(pipex, "here_doc");
}

void	heredoc_write(t_pipex *pipex, char *lim)
{
	char	*line;
	size_t	len;

	len = ft_strlen(lim);
	while (1)
	{
		ft_putstr_fd("pipex heredoc>", 1);
		line = get_next_line(0);
		if (!line)
		{
			close_fd(pipex);
			error_ret(pipex, "heredoc input failed\n");
		}
		if (!ft_strncmp(line, lim, len) && line[len] == '\n')
			break ;
		if (write(pipex->fd_in, line, ft_strlen(line)) == -1)
		{
			close_fd(pipex);
			error_ret(pipex, "heredoc input failed\n");
		}
		free(line);
	}
	free(line);
}
