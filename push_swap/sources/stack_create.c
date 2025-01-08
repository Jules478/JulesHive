/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:48:23 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/22 17:58:44 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

t_stack	*ft_stacknew(long content)
{
	t_stack	*elmt;

	elmt = malloc(sizeof(t_stack));
	if (!elmt)
		return (NULL);
	elmt->content = content;
	elmt->next = NULL;
	return (elmt);
}

void	ft_stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	if (!stack)
	{
		*stack = new;
		return ;
	}
	last = ft_stacklast(*stack);
	last->next = new;
}

int	ft_stacksize(t_stack *stack)
{
	t_stack	*current;
	int		count;

	current = stack;
	count = 0;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	freeall(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		(*stack)->content = 0;
		free(*stack);
		*stack = temp;
	}
}
