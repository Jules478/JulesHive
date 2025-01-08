/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:42:17 by mpierce           #+#    #+#             */
/*   Updated: 2025/01/02 15:19:23 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	error_ret(t_stack **stack, char **array)
{
	if (array)
		free_array(array);
	if (stack)
		freeall(stack);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_stackiter(t_stack *lst, void (*f)(void *))
{
	t_stack	*temp;

	temp = lst;
	while (temp)
	{
		f(&temp->content);
		temp = temp->next;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;

	stack_a = param_check(argc, argv);
	if (!validation(stack_a))
		error_ret(&stack_a, NULL);
	if (!sortcheck(stack_a))
		sorter(&stack_a);
	freeall(&stack_a);
	return (0);
}
