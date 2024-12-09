/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:46:57 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/09 13:01:43 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst) // returns number of elements in a list
{
	t_list	*current;
	int		count;

	current = lst; // create new pointer to start of list
	count = 0;
	while (current != NULL) // iterate through list while the current element is not null
	{
		count++;
		current = current->next;
	}
	return (count);
}
