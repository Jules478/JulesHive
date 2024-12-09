/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:03:50 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/09 12:45:53 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *)) // apply function to each element of a list
{
	t_list	*temp;

	temp = lst; // assign temporary pointer to list
	while (temp) // iterate through each element of the list passing it to the function
	{
		f(temp->content);
		temp = temp->next;
	}
}
