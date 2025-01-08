/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils_ab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:22:50 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/22 17:58:30 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	rarb(t_stack *stack_a, t_stack *stack_b, int c)
{
	int	i;

	i = locate_index_b(stack_b, c);
	if (i < index_search(stack_a, c))
		i = index_search(stack_a, c);
	return (i);
}

int	rrarrb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (locate_index_b(b, c))
		i = ft_stacksize(b) - locate_index_b(b, c);
	if ((i < (ft_stacksize(a) - index_search(a, c))) && index_search(a, c))
		i = ft_stacksize(a) - index_search(a, c);
	return (i);
}

int	rrarb(t_stack *stack_a, t_stack *stack_b, int c)
{
	int	i;

	i = 0;
	if (index_search(stack_a, c))
		i = ft_stacksize(stack_a) - index_search(stack_a, c);
	i += locate_index_b(stack_b, c);
	return (i);
}

int	rarrb(t_stack *stack_a, t_stack *stack_b, int c)
{
	int	i;

	i = 0;
	if (locate_index_b(stack_b, c))
		i = ft_stacksize(stack_b) - locate_index_b(stack_b, c);
	i += index_search(stack_a, c);
	return (i);
}
