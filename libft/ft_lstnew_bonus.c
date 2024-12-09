/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:09:18 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/09 13:00:14 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content) // create new list
{
	t_list	*elmt;

	elmt = malloc(sizeof(t_list)); // allocate memory for the first element
	if (!elmt)
		return (NULL);
	elmt->content = content; // assign content as the first element of list
	elmt->next = NULL;
	return (elmt);
}
