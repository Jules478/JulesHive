/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:09:18 by mpierce           #+#    #+#             */
/*   Updated: 2024/11/12 13:54:39 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elmt;

	elmt = malloc(sizeof(t_list));
	if (!elmt)
		return (NULL);
	elmt->content = content;
	elmt->next = NULL;
	return (elmt);
}
