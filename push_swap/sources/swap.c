/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:17:11 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/23 14:12:59 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*temp;

	if (ft_stacksize(*stack) < 2)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}

void	sa(t_stack **stack, int i)
{
	swap(stack);
	if (i == 0)
		write(1, "sa\n", 3);
}

void	sb(t_stack **stack, int i)
{
	swap(stack);
	if (i == 0)
		write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b, int i)
{
	swap(stack_a);
	swap(stack_b);
	if (i == 0)
		write(1, "sa\n", 3);
}
