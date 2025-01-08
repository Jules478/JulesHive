/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:25:57 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/22 17:58:07 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	maxint(t_stack *stack)
{
	int	i;

	i = stack->content;
	while (stack)
	{
		if (stack->content > i)
			i = stack->content;
		stack = stack->next;
	}
	return (i);
}

int	minint(t_stack *stack)
{
	int	i;

	i = stack->content;
	while (stack)
	{
		if (stack->content < i)
			i = stack->content;
		stack = stack->next;
	}
	return (i);
}

int	index_search(t_stack *stack, int num)
{
	int	i;

	i = 0;
	while (stack && stack->content != num)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	locate_index_b(t_stack *stack_b, int num)
{
	int		i;
	t_stack	*temp;

	i = 1;
	if (num > stack_b->content && num < ft_stacklast(stack_b)->content)
		i = 0;
	else if (num > maxint(stack_b) || num < minint(stack_b))
		i = index_search(stack_b, maxint(stack_b));
	else
	{
		temp = stack_b->next;
		while (stack_b->content < num || temp->content > num)
		{
			stack_b = stack_b->next;
			temp = stack_b->next;
			i++;
		}
	}
	return (i);
}

int	locate_index_a(t_stack *stack_a, int num)
{
	int		i;
	t_stack	*temp;

	i = 1;
	if (num < stack_a->content && num > ft_stacklast(stack_a)->content)
		i = 0;
	else if (num > maxint(stack_a) || num < minint(stack_a))
		i = index_search(stack_a, minint(stack_a));
	else
	{
		temp = stack_a->next;
		while (stack_a->content > num || temp->content < num)
		{
			stack_a = stack_a->next;
			temp = stack_a->next;
			i++;
		}
	}
	return (i);
}
