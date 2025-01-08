/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:29:22 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/23 14:15:55 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	sort_three(t_stack **stack)
{
	if (minint(*stack) == (*stack)->content)
	{
		rra(stack, 0);
		sa(stack, 0);
	}
	else if (maxint(*stack) == (*stack)->content)
	{
		ra(stack, 0);
		if (!sortcheck(*stack))
			sa(stack, 0);
	}
	else
	{
		if (index_search(*stack, maxint(*stack)) == 1)
			rra(stack, 0);
		else
			sa(stack, 0);
	}
}
