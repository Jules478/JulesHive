/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:29:50 by mpierce           #+#    #+#             */
/*   Updated: 2025/02/18 15:09:48 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	open_heredoc(t_pipex *pipex, char *lim)
{
	pipex->fd_in = pipex->pipex_fd[1];
	if (pipex->fd_in == -1)
		error_ret(pipex, "here_doc", EXIT_FAILURE);
	heredoc_write(pipex, lim);
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
			free(line);
			error_ret_noerrno(pipex, "\nheredoc input failed\n", EXIT_FAILURE);
		}
		if (!ft_strncmp(line, lim, len) && line[len] == '\n')
			break ;
		if (write(pipex->fd_in, line, ft_strlen(line)) == -1)
		{
			free(line);
			error_ret_noerrno(pipex, "\nheredoc input failed\n", EXIT_FAILURE);
		}
		free(line);
	}
	free(line);
}

void	open_outfile_heredoc(t_pipex *pipex)
{
	int	ex_code;

	pipex->fd_out = open(pipex->argv[pipex->out], O_WRONLY \
		| O_CREAT | O_APPEND, 0644);
	if (pipex->fd_out == -1)
	{
		if (errno == ENOENT)
			ex_code = 127;
		else if (errno == EACCES)
			ex_code = 126;
		else
			ex_code = 1;
		close_fd(pipex);
		error_ret(pipex, pipex->argv[pipex->out], ex_code);
	}
}
