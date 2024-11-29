/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 12:29:32 by mpierce           #+#    #+#             */
/*   Updated: 2024/11/04 17:08:15 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	memory;
	void	*ptr;

	if (SIZE_MAX / size < nmemb)
		return (0);
	memory = size * nmemb;
	ptr = malloc(memory);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, memory);
	return (ptr);
}
