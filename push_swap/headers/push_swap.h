/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:08:29 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/23 14:14:16 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <unistd.h>
# include "../libftmaster/libft.h"

typedef struct s_stack
{
	long			content;
	struct s_stack	*next;
}	t_stack;

int		error_ret(t_stack **stack, char **array);
void	free_array(char	**arr);
int		validation(t_stack *stack);
t_stack	*param_check(int argc, char **argv);
int		ft_stacksize(t_stack *stack);
void	ft_stack_add_back(t_stack **stack, t_stack *new);
t_stack	*ft_stacklast(t_stack *stack);
t_stack	*ft_stacknew(long content);
void	freeall(t_stack **stack);
int		sortcheck(t_stack *stack_a);
void	sorter(t_stack **stack_a);
int		rotation_calc_ab(t_stack **stack_a, t_stack **stack_b);
int		rotation_calc_ba(t_stack **stack_a, t_stack **stack_b);
int		rarb(t_stack *stack_a, t_stack *stack_b, int c);
int		do_rarb(t_stack **stack_a, t_stack **stack_b, int c, char d);
int		rarb_a(t_stack *stack_a, t_stack *stack_b, int c);
int		rrarrb(t_stack *stack_a, t_stack *stack_b, int c);
int		do_rrarrb(t_stack **stack_a, t_stack **stack_b, int c, char d);
int		rrarrb_a(t_stack *stack_a, t_stack *stack_b, int c);
int		rarrb(t_stack *stack_a, t_stack *stack_b, int c);
int		do_rarrb(t_stack **stack_a, t_stack **stack_b, int c, char d);
int		rarrb_a(t_stack *stack_a, t_stack *stack_b, int c);
int		rrarb(t_stack *stack_a, t_stack *stack_b, int c);
int		do_rrarb(t_stack **stack_a, t_stack **stack_b, int c, char d);
int		rrarb_a(t_stack *stack_a, t_stack *stack_b, int c);
int		maxint(t_stack *stack);
int		minint(t_stack *stack);
int		index_search(t_stack *stack, int num);
int		locate_index_a(t_stack *stack_a, int num);
int		locate_index_b(t_stack *stack_b, int num);
void	sort_three(t_stack **stack);
void	sa(t_stack **stack, int i);
void	sb(t_stack **stack, int i);
void	ss(t_stack **stack_a, t_stack **stack_b, int i);
void	pa(t_stack **stack_a, t_stack **stack_b, int i);
void	pb(t_stack **stack_a, t_stack **stack_b, int i);
void	ra(t_stack **stack, int i);
void	rb(t_stack **stack, int i);
void	rr(t_stack **stack_a, t_stack **stack_b, int i);
void	rra(t_stack **stack, int i);
void	rrb(t_stack **stack, int i);
void	rrr(t_stack **stack_a, t_stack **stack_b, int i);

#endif