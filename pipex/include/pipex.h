/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:48:31 by mpierce           #+#    #+#             */
/*   Updated: 2025/02/14 17:48:56 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include <stdio.h>
# include "../libftmaster/libft.h"

typedef struct s_pipex
{
	int		argc;
	char	**argv;
	char	**envp;
	int		out;
	int		cmd_count;
	int		fd_in;
	int		fd_out;
	int		pipex_fd[2];
	int		prev_fd;
	char	**full_cmd;
	pid_t	*pids;
	int		pid_index;
	char	*cmd_path;
}				t_pipex;

void	error_ret(t_pipex *pipex, char *name, int ex_code);
void	assign_to_struct(t_pipex *pipex, int argc, char **argv, char **envp);
void	free_all(t_pipex *pipex);
char	*find_path(char *cmd, char **envp);
void	do_pipe(t_pipex *pipex, int heredoc, int *ex_stat);
void	do_mid_cmd(char	*cmd, t_pipex *pipex);
char	*get_path(t_pipex *pipex, char *cmd, char **envp);
void	do_first_cmd(char *cmd, t_pipex *pipex);
void	do_last_cmd(char *cmd, t_pipex *pipex);
void	open_infile(t_pipex *pipex);
void	close_fd(t_pipex *pipex);
void	next_pipe(t_pipex *pipex, int check);
void	open_outfile(t_pipex *pipex);
void	error_ret_noerrno(t_pipex *pipex, char *name, int ex_code);
void	validation(t_pipex *pipex, char *cmd);
void	error_ret_open(t_pipex *pipex, char *name, int ex_code);

#endif