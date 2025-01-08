/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:57:21 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/23 14:11:56 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	revrotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	if (ft_stacksize(*stack) < 2)
		return ;
	temp = *stack;
	while (temp->next->next)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **stack, int i)
{
	revrotate(stack);
	if (i == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **stack, int i)
{
	revrotate(stack);
	if (i == 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int i)
{
	revrotate(stack_a);
	revrotate(stack_b);
	if (i == 0)
		write(1, "rrr\n", 4);
}
