/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:23:59 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/22 17:58:04 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	dup_check(t_stack *param, int check)
{
	param = param->next;
	while (param)
	{
		if (param->content == check)
			return (0);
		param = param->next;
	}
	return (1);
}

int	validation(t_stack *param)
{
	while (param->next)
	{
		if (!dup_check(param, param->content))
			return (0);
		param = param->next;
	}
	return (1);
}
