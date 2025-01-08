/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:41:51 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/23 14:11:19 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (ft_stacksize(*stack_b) < 1)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
}

void	pa(t_stack **stack_a, t_stack **stack_b, int i)
{
	push(stack_a, stack_b);
	if (i == 0)
		write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b, int i)
{
	push(stack_b, stack_a);
	if (i == 0)
		write(1, "pb\n", 3);
}
