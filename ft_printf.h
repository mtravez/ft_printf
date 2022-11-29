/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:32:04 by mtravez           #+#    #+#             */
/*   Updated: 2022/11/29 11:44:37 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

int	ft_hexprint(unsigned int n, char uplo);
int	ft_putstr(char *string);
int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_put_unsigned(unsigned int n);
int	ft_printf(const char *string, ...);
int	ft_print_ptr(unsigned long long point);
#endif