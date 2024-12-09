/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:32:32 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/09 13:12:11 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd) // write string to specified file descriptor followed by new line
{
	if (!s || fd < 1) // check empty string and invalid file descriptor
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
