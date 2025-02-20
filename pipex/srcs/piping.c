/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:07:05 by mpierce           #+#    #+#             */
/*   Updated: 2025/02/20 12:04:34 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	do_pipe(t_pipex *pipex, int heredoc, int *ex_stat)
{
	pipex->pids = malloc((pipex->cmd_count - heredoc) * sizeof(pid_t));
	if (!pipex->pids)
		error_ret_noerrno(pipex, "Pipex malloc failure\n", EXIT_FAILURE);
	if (pipe(pipex->pipex_fd) < 0)
		error_ret(pipex, "Pipex", EXIT_FAILURE);
	do_first_cmd(pipex->argv[1], pipex);
	next_pipe(pipex, 0);
	do_last_cmd(pipex->argv[pipex->cmd_count], pipex);
	close_fd(pipex);
	pipex->pid_index = 0;
	while (pipex->pid_index < pipex->cmd_count - heredoc)
		waitpid(pipex->pids[pipex->pid_index++], ex_stat, 0);
}

void	do_first_cmd(char *cmd, t_pipex *pipex)
{
	pipex->pids[pipex->pid_index++] = fork();
	if (pipex->pids[pipex->pid_index - 1] < 0)
		error_ret_noerrno(pipex, "Fork failure\n", EXIT_FAILURE);
	if (pipex->pids[pipex->pid_index - 1])
		return ;
	open_infile(pipex);
	validation(pipex, cmd);
	if (dup2(pipex->fd_in, 0) < 0 || dup2(pipex->pipex_fd[1], 1) < 0)
		error_ret(pipex, "Pipex", EXIT_FAILURE);
	close_fd(pipex);
	execve(pipex->cmd_path, pipex->full_cmd, pipex->envp);
	error_ret(pipex, pipex->full_cmd[0], 127);
}

void	do_last_cmd(char *cmd, t_pipex *pipex)
{
	pipex->pids[pipex->pid_index] = fork();
	if (pipex->pids[pipex->pid_index] < 0)
		error_ret_noerrno(pipex, "Fork failure\n", EXIT_FAILURE);
	if (pipex->pids[pipex->pid_index])
		return ;
	open_outfile(pipex);
	validation(pipex, cmd);
	if (dup2(pipex->prev_fd, 0) < 0 || dup2(pipex->fd_out, 1) < 0)
		error_ret(pipex, "Pipex", EXIT_FAILURE);
	close_fd(pipex);
	execve(pipex->cmd_path, pipex->full_cmd, pipex->envp);
	error_ret(pipex, pipex->full_cmd[0], 127);
}
