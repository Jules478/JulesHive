/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:42:40 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/23 15:45:02 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	error_ret(t_stack **stack, char **array)
{
	ft_printf("Error\n");
	if (array)
		free_array(array);
	if (stack)
		freeall(stack);
	exit(-1);
}

int	sortcheck(t_stack *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
