/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:35:16 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/23 14:12:30 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	if (ft_stacksize(*stack) < 2)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	last = ft_stacklast(*stack);
	last->next = temp;
	temp->next = NULL;
}

void	ra(t_stack **stack, int i)
{
	rotate(stack);
	if (i == 0)
		write(1, "ra\n", 3);
}

void	rb(t_stack **stack, int i)
{
	rotate(stack);
	if (i == 0)
		write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b, int i)
{
	rotate(stack_a);
	rotate(stack_b);
	if (i == 0)
		write(1, "rr\n", 3);
}
