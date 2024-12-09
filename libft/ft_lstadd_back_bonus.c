/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:53:44 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/09 12:31:50 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new) // add a new element to the end of a list
{
	t_list	*last;

	if (!new) // check that new element to add is not null
		return ;
	if (!*lst) // if the list does not exist we make the new element the first element
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst); // get a pointer to the last element of the list
	last->next = new;
}
