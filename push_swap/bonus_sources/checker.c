/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:18:17 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/23 14:31:32 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	op_check2(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (line[2] == 'a')
		rra(stack_a, 1);
	else if (line[2] == 'b')
		rrb(stack_b, 1);
	else if (line[2] == 'r')
		rrr(stack_a, stack_b, 1);
}

char	*op_check(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		sa(stack_a, 1);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		sb(stack_b, 1);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		pa(stack_a, stack_b, 1);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		pb(stack_a, stack_b, 1);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ra(stack_a, 1);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		rb(stack_b, 1);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\n')
		op_check2(stack_a, stack_b, line);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		rr(stack_a, stack_b, 1);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ss(stack_a, stack_b, 1);
	else
		error_ret(NULL, NULL);
	return (get_next_line(0));
}

void	op_manage(t_stack **stack_a, t_stack **stack_b, char *line)
{
	char	*temp;

	while (line && *line != '\n')
	{
		temp = line;
		line = op_check(stack_a, stack_b, line);
		free(temp);
	}
	if (*stack_b)
		write(1, "KO\n", 3);
	if (!sortcheck(*stack_a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(line);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	stack_a = param_check(argc, argv);
	stack_b = NULL;
	if (!validation(stack_a))
		error_ret(&stack_a, NULL);
	line = get_next_line(0);
	if (!line && !sortcheck(stack_a))
		write(1, "KO\n", 3);
	else if (!line && sortcheck(stack_a))
		write(1, "OK\n", 3);
	else
		op_manage(&stack_a, &stack_b, line);
	freeall(&stack_a);
	freeall(&stack_b);
	return (0);
}
