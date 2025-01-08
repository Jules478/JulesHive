/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:14:22 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/22 17:58:35 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	rotation_calc_ab(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*temp;

	temp = *stack_a;
	i = rrarrb(*stack_a, *stack_b, (*stack_a)->content);
	while (temp)
	{
		if (i > rarb(*stack_a, *stack_b, temp->content))
			i = rarb(*stack_a, *stack_b, temp->content);
		if (i > rrarrb(*stack_a, *stack_b, temp->content))
			i = rrarrb(*stack_a, *stack_b, temp->content);
		if (i > rarrb(*stack_a, *stack_b, temp->content))
			i = rarrb(*stack_a, *stack_b, temp->content);
		if (i > rrarb(*stack_a, *stack_b, temp->content))
			i = rrarb(*stack_a, *stack_b, temp->content);
		temp = temp->next;
	}
	return (i);
}

int	rotation_calc_ba(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*temp;

	temp = *stack_b;
	i = rrarrb_a(*stack_a, *stack_b, (*stack_b)->content);
	while (temp)
	{
		if (i > rarb_a(*stack_a, *stack_b, temp->content))
			i = rarb_a(*stack_a, *stack_b, temp->content);
		if (i > rrarrb_a(*stack_a, *stack_b, temp->content))
			i = rrarrb_a(*stack_a, *stack_b, temp->content);
		if (i > rarrb_a(*stack_a, *stack_b, temp->content))
			i = rarrb_a(*stack_a, *stack_b, temp->content);
		if (i > rrarb_a(*stack_a, *stack_b, temp->content))
			i = rrarb_a(*stack_a, *stack_b, temp->content);
		temp = temp->next;
	}
	return (i);
}
