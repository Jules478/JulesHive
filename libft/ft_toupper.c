/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:12:56 by mpierce           #+#    #+#             */
/*   Updated: 2024/12/09 17:50:55 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c) // convert lowercase letters to uppercase
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}
