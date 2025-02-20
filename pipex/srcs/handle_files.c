/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:02:52 by mpierce           #+#    #+#             */
/*   Updated: 2025/02/18 16:37:47 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	open_infile(t_pipex *pipex)
{
	int	dir;

	if (*pipex->argv[0] == 0)
		error_ret_noerrno(pipex, "Pipex: No such file or directory\n", 1);
	dir = open(pipex->argv[0], __O_DIRECTORY);
	if (dir != -1)
	{
		close(dir);
		write(2, pipex->argv[0], ft_strlen(pipex->argv[0]));
		free(pipex->cmd_path);
		error_ret_noerrno(pipex, ": Is a directory\n", 1);
	}
	pipex->fd_in = open(pipex->argv[0], O_RDONLY, 0644);
	if (pipex->fd_in == -1)
	{
		close_fd(pipex);
		error_ret_open(pipex, pipex->argv[0], 1);
	}
}

void	open_outfile(t_pipex *pipex)
{
	int	dir;

	if (*pipex->argv[pipex->out] == 0)
		error_ret_noerrno(pipex, "Pipex: No such file or directory\n", 1);
	dir = open(pipex->argv[pipex->out], __O_DIRECTORY);
	if (dir != -1)
	{
		close(dir);
		write(2, pipex->argv[pipex->out], ft_strlen(pipex->argv[pipex->out]));
		free(pipex->cmd_path);
		error_ret_noerrno(pipex, ": Is a directory\n", 1);
	}
	pipex->fd_out = open(pipex->argv[pipex->out], O_WRONLY \
		| O_CREAT | O_TRUNC, 0644);
	if (pipex->fd_out == -1)
	{
		close_fd(pipex);
		error_ret_open(pipex, pipex->argv[pipex->out], 1);
	}
}

void	close_fd(t_pipex *pipex)
{
	if (pipex->fd_in != -1)
		close(pipex->fd_in);
	if (pipex->fd_out != -1)
		close(pipex->fd_out);
	if (pipex->pipex_fd[0] != -1)
		close(pipex->pipex_fd[0]);
	if (pipex->pipex_fd[1] != -1)
		close(pipex->pipex_fd[1]);
	if (pipex->prev_fd != -1)
		close(pipex->prev_fd);
}

void	next_pipe(t_pipex *pipex, int check)
{
	if (pipex->prev_fd != -1)
		close(pipex->prev_fd);
	close(pipex->pipex_fd[1]);
	pipex->pipex_fd[1] = -1;
	pipex->prev_fd = pipex->pipex_fd[0];
	pipex->pipex_fd[0] = -1;
	if (check)
		return ;
	if (pipe(pipex->pipex_fd) < 0)
		error_ret(pipex, "Pipex", EXIT_FAILURE);
}
