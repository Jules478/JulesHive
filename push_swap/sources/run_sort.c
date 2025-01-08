/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:05:51 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/23 14:15:10 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	do_rarb(t_stack **stack_a, t_stack **stack_b, int c, char d)
{
	if (d == 'a')
	{
		while ((*stack_a)->content != c && locate_index_b(*stack_b, c) > 0)
			rr(stack_a, stack_b, 0);
		while ((*stack_a)->content != c)
			ra(stack_a, 0);
		while (locate_index_b(*stack_b, c) > 0)
			rb (stack_b, 0);
		pb(stack_a, stack_b, 0);
	}
	else
	{
		while ((*stack_b)->content != c && locate_index_a(*stack_a, c) > 0)
			rr(stack_a, stack_b, 0);
		while ((*stack_b)->content != c)
			rb(stack_b, 0);
		while (locate_index_a(*stack_a, c) > 0)
			ra(stack_a, 0);
		pa(stack_a, stack_b, 0);
	}
	return (-1);
}

int	do_rrarrb(t_stack **stack_a, t_stack **stack_b, int c, char d)
{
	if (d == 'a')
	{
		while ((*stack_a)->content != c && locate_index_b(*stack_b, c) > 0)
			rrr(stack_a, stack_b, 0);
		while ((*stack_a)->content != c)
			rra(stack_a, 0);
		while (locate_index_b(*stack_b, c) > 0)
			rrb (stack_b, 0);
		pb(stack_a, stack_b, 0);
	}
	else
	{
		while ((*stack_b)->content != c && locate_index_a(*stack_a, c) > 0)
			rrr(stack_a, stack_b, 0);
		while ((*stack_b)->content != c)
			rrb(stack_b, 0);
		while (locate_index_a(*stack_a, c) > 0)
			rra(stack_a, 0);
		pa(stack_a, stack_b, 0);
	}
	return (-1);
}

int	do_rarrb(t_stack **stack_a, t_stack **stack_b, int c, char d)
{
	if (d == 'a')
	{
		while ((*stack_a)->content != c)
			ra(stack_a, 0);
		while (locate_index_b(*stack_b, c) > 0)
			rrb(stack_b, 0);
		pb(stack_a, stack_b, 0);
	}
	else
	{
		while (locate_index_a(*stack_a, c) > 0)
			ra(stack_a, 0);
		while ((*stack_b)->content != c)
			rrb(stack_b, 0);
		pa(stack_a, stack_b, 0);
	}
	return (-1);
}

int	do_rrarb(t_stack **stack_a, t_stack **stack_b, int c, char d)
{
	if (d == 'a')
	{
		while ((*stack_a)->content != c)
			rra(stack_a, 0);
		while (locate_index_b(*stack_b, c) > 0)
			rb(stack_b, 0);
		pb(stack_a, stack_b, 0);
	}
	else
	{
		while (locate_index_a(*stack_a, c) > 0)
			rra(stack_a, 0);
		while ((*stack_b)->content != c)
			rb(stack_b, 0);
		pa(stack_a, stack_b, 0);
	}
	return (-1);
}
