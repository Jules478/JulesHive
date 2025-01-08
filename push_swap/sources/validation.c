/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:18:33 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/30 12:34:45 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_atoistrict(char *nptr, int neg, t_stack *stack, char **temp)
{
	size_t	i;
	long	num;

	i = 0;
	num = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == 45)
	{
		neg *= -1;
		i++;
	}
	else if (nptr[i] == 43)
		i++;
	if (!nptr[i])
		error_ret(&stack, temp);
	while (nptr[i])
	{
		if (nptr[i] < 48 || nptr[i] > 57)
			error_ret(&stack, temp);
		num = num * 10 + (nptr[i++] - 48);
		if ((num > 2147483647 && neg == 1) || (num > 2147483648 && neg == -1))
			error_ret(&stack, temp);
	}
	return (num * neg);
}

t_stack	*split_string(char **argv)
{
	t_stack	*stack_a;
	char	**temp;
	int		i;
	int		num;

	temp = ft_split(argv[1], 32);
	stack_a = NULL;
	if (!*temp || !temp)
		error_ret(&stack_a, temp);
	i = 0;
	num = ft_atoistrict(temp[i++], 1, stack_a, temp);
	stack_a = ft_stacknew(num);
	while (temp[i])
	{
		num = ft_atoistrict(temp[i], 1, stack_a, temp);
		ft_stack_add_back(&stack_a, ft_stacknew(num));
		i++;
	}
	free_array(temp);
	return (stack_a);
}

t_stack	*param_check(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;
	int		num;

	i = 1;
	if (argc == 1)
		exit(0);
	else if (argc == 2)
		stack_a = split_string(argv);
	else
	{
		stack_a = NULL;
		num = ft_atoistrict(argv[i++], 1, stack_a, NULL);
		stack_a = ft_stacknew(num);
		while (argv[i])
		{
			num = ft_atoistrict(argv[i], 1, stack_a, NULL);
			ft_stack_add_back(&stack_a, ft_stacknew(num));
			i++;
		}
	}
	return (stack_a);
}
