/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:20:33 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/09 17:51:01 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c) // convert uppcase letters to lowercase
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}
