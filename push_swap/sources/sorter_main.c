/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:06:39 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/23 14:17:50 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

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

void	sort_til_three(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*temp;

	while (ft_stacksize(*stack_a) > 3 && !sortcheck(*stack_a))
	{
		temp = *stack_a;
		i = rotation_calc_ab(stack_a, stack_b);
		while (i >= 0)
		{
			if (i == rarb(*stack_a, *stack_b, temp->content))
				i = do_rarb(stack_a, stack_b, temp->content, 'a');
			else if (i == rrarrb(*stack_a, *stack_b, temp->content))
				i = do_rrarrb(stack_a, stack_b, temp->content, 'a');
			else if (i == rarrb(*stack_a, *stack_b, temp->content))
				i = do_rarrb(stack_a, stack_b, temp->content, 'a');
			else if (i == rrarb(*stack_a, *stack_b, temp->content))
				i = do_rrarb(stack_a, stack_b, temp->content, 'a');
			else
				temp = temp->next;
		}
	}
}

t_stack	*sort_b(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_stacksize(*stack_a) > 3 && !sortcheck(*stack_a))
		pb(stack_a, &stack_b, 0);
	if (ft_stacksize(*stack_a) > 3 && !sortcheck(*stack_a))
		pb(stack_a, &stack_b, 0);
	if (ft_stacksize(*stack_a) > 3 && !sortcheck(*stack_a))
		sort_til_three(stack_a, &stack_b);
	if (!sortcheck(*stack_a))
		sort_three(stack_a);
	return (stack_b);
}

t_stack	**sort_a(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*temp;

	while (*stack_b)
	{
		temp = *stack_b;
		i = rotation_calc_ba(stack_a, stack_b);
		while (i >= 0)
		{
			if (i == rarb_a(*stack_a, *stack_b, temp->content))
				i = do_rarb(stack_a, stack_b, temp->content, 'b');
			else if (i == rrarrb_a(*stack_a, *stack_b, temp->content))
				i = do_rrarrb(stack_a, stack_b, temp->content, 'b');
			else if (i == rarrb_a(*stack_a, *stack_b, temp->content))
				i = do_rarrb(stack_a, stack_b, temp->content, 'b');
			else if (i == rrarb_a(*stack_a, *stack_b, temp->content))
				i = do_rrarb(stack_a, stack_b, temp->content, 'b');
			else
				temp = temp->next;
		}
	}
	return (stack_a);
}

void	sorter(t_stack **stack_a)
{
	int		i;
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_stacksize(*stack_a) == 2)
		sa(stack_a, 0);
	else
	{
		stack_b = sort_b(stack_a);
		stack_a = sort_a(stack_a, &stack_b);
		i = index_search(*stack_a, minint(*stack_a));
		if (i < ft_stacksize(*stack_a) - i)
		{
			while ((*stack_a)->content != minint(*stack_a))
				ra(stack_a, 0);
		}
		else
		{
			while ((*stack_a)->content != minint(*stack_a))
				rra(stack_a, 0);
		}
	}
}
