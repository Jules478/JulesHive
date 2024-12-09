/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:43:34 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/09 12:34:02 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *)) // empty an existing list of all elements
{
	t_list	*temp;

	if (!lst || !del) // check for the list and deleting function not being null
		return ;
	while (*lst) // work through all elements of the list and empty each in turn
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	free(*lst); // free the pointer to the list
	*lst = NULL; // set the pointer to null
}
