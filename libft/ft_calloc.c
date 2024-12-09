/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:29:32 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/09 12:18:21 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size) // allocate new string and set all positions to null
{
	size_t	memory;
	void	*ptr;

	if (SIZE_MAX / size < nmemb) // overflow check
		return (0);
	memory = size * nmemb;
	ptr = malloc(memory);
	if (ptr == NULL) // malloc fail check
		return (NULL);
	ft_bzero(ptr, memory);
	return (ptr);
}
