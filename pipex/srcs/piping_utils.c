/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:45:47 by mpierce           #+#    #+#             */
/*   Updated: 2025/02/18 16:18:28 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*find_path(char *cmd, char **envp)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		path = ft_substr(envp[i], 0, j);
		if (!ft_strcmp(path, cmd))
		{
			free(path);
			return (envp[i] + j + 1);
		}
		free(path);
		i++;
	}
	return (NULL);
}

char	*get_path(t_pipex *pipex, char *cmd, char **envp)
{
	int		i;
	char	*exe;
	char	**full_path;
	char	*part_path;
	char	*path;

	i = -1;
	path = find_path("PATH", envp);
	if (!path)
		return (cmd);
	full_path = ft_quotesplit(path, ':');
	while (full_path[++i])
	{
		part_path = ft_strjoin(full_path[i], "/");
		exe = ft_strjoin(part_path, pipex->full_cmd[0]);
		free(part_path);
		if (!access(exe, F_OK | X_OK))
		{
			free_array(&full_path);
			return (exe);
		}
		free(exe);
	}
	free_array(&full_path);
	return (cmd);
}

void	validation(t_pipex *pipex, char *cmd)
{
	int	dir;

	if (*cmd == 0)
		error_ret_noerrno(pipex, "Pipex: command not found:\n", 127);
	dir = open(cmd, __O_DIRECTORY);
	if (dir != -1)
	{
		close(dir);
		write(2, cmd, ft_strlen(cmd));
		error_ret_noerrno(pipex, ": Is a directory\n", 126);
	}
	pipex->full_cmd = ft_quotesplit(cmd, 32);
	if (ft_strchr(cmd, '/'))
		pipex->cmd_path = pipex->full_cmd[0];
	else
		pipex->cmd_path = get_path(pipex, pipex->full_cmd[0], pipex->envp);
}
