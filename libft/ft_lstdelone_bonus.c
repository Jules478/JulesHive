/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:35:35 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/09 12:40:16 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *)) // empty the current element of list
{
	if (!lst || !del) // check if the list and delete function exist
		return ;
	del(lst->content); // pass the element to a delete function
	free(lst); // free the pointer to the element
}
