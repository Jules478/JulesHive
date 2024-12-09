/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:02:33 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/09 12:56:44 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *)) // create copy of a list and apply function to each element
{
	t_list	*newlist;
	t_list	*newcont;

	if (!lst || !f || !del) // check list, function, and delete function are not null
		return (NULL);
	newlist = NULL;
	while (lst) // iterate through original list
	{
		newcont = ft_lstnew(f(lst->content)); // assign elements of the original list to the new list after running through function
		if (!newcont) // if function returns null the new list is emptied and null is returned
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, newcont); // add new element to the end of the new list
		lst = lst->next;
	}
	return (newlist);
}
