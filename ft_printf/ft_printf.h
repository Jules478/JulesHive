/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:37:11 by mpierce           #+#    #+#             */
/*   Updated: 2024/11/29 15:53:15 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

# define FORMATS "diuxXscp%"

int	ft_printf(const char *format, ...);
int	print_ptr(unsigned long int n);
int	print_hex(unsigned int n, char format);
int	print_uint(unsigned int n);
int	print_prcnt(void);
int	print_char(int c);
int	print_str(char *str);
int	print_int(int n);

#endif
