/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils_ba.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:40:09 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/22 17:58:32 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	rarb_a(t_stack *stack_a, t_stack *stack_b, int c)
{
	int	i;

	i = locate_index_a(stack_a, c);
	if (i < index_search(stack_b, c))
		i = index_search(stack_b, c);
	return (i);
}

int	rrarrb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (locate_index_a(a, c))
		i = ft_stacksize(a) - locate_index_a(a, c);
	if ((i < (ft_stacksize(b) - index_search(b, c))) && index_search(b, c))
		i = ft_stacksize(b) - index_search(b, c);
	return (i);
}

int	rarrb_a(t_stack *stack_a, t_stack *stack_b, int c)
{
	int	i;

	i = 0;
	if (index_search(stack_b, c))
		i = ft_stacksize(stack_b) - index_search(stack_b, c);
	i += locate_index_a(stack_a, c);
	return (i);
}

int	rrarb_a(t_stack *stack_a, t_stack *stack_b, int c)
{
	int	i;

	i = 0;
	if (locate_index_a(stack_a, c))
		i = ft_stacksize(stack_a) - locate_index_a(stack_a, c);
	i += index_search(stack_b, c);
	return (i);
}
