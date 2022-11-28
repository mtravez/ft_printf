/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:51:31 by mtravez           #+#    #+#             */
/*   Updated: 2022/11/28 16:58:28 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

static int	ft_print_vars(char *string, va_list params)
{
	if (string[1] == 'c')
		return (ft_putchar(va_arg(params, int)));
	else if (string[1] == 's')
		return (ft_putstr(va_arg(params, char *)));
	else if (string[1] == 'x')
		return (ft_hexprint((unsigned int)va_arg(params, int), 'a'));
	else if (string[1] == 'X')
		return (ft_hexprint((unsigned int)va_arg(params, int), 'A'));
	else if (string[1] == 'i')
		return (ft_putnbr(va_arg(params, int)));
	else if (string[1] == 'd')
		return (ft_putnbr(va_arg(params, int)));
	else if (string[1] == 'u')
		return (ft_put_unsigned(va_arg(params, unsigned int)));
	else if (string[1] == 'p')
		return (ft_print_ptr(va_arg(params, unsigned long long)));
	else if (string[1] == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *string, ...)
{
	int		index;
	int		count;
	va_list	ap;

	index = 0;
	count = 0;
	va_start(ap, string);
	if (!string)
		return (0);
	while (string[index])
	{
		if (string[index] == '%')
		{
			count += ft_print_vars((char *)&(string[index]), ap);
			index++;
		}
		else
		count += ft_putchar(string[index]);
		index++;
	}
	return (count);
}