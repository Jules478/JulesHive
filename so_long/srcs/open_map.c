/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:44:51 by mpierce           #+#    #+#             */
/*   Updated: 2025/01/14 14:32:54 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	open_map(char *map)
{
	char	*temp;
	int		fd;

	temp = ft_strjoin("maps/", map);
	fd = open(temp, O_RDONLY);
	free(temp);
	return (fd);
}
