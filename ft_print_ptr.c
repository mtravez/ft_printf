/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:47:04 by mtravez           #+#    #+#             */
/*   Updated: 2022/11/28 15:53:07 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_digits_ptr(unsigned long long n)
{
	int	sum;

	sum = 0;
	while (n)
	{
		n = n / 16;
		sum++;
	}
	if (sum == 0)
		sum++;
	return (sum);
}

static void	ft_print_hex_ptr(unsigned long long n)
{
	if (n >= 16)
	{
		ft_print_hex_ptr(n / 16);
		n = (n % 16);
	}
	if (n > 9)
		ft_putchar_fd('a' + (n % 10), 1);
	else
		ft_putchar_fd(n + '0', 1);
}

static int	ft_ptr_hex(unsigned long long point)
{
	ft_print_hex_ptr(point);
	return (get_digits_ptr(point));
}

int	ft_print_ptr(unsigned long long point)
{
	int	count;

	count = 0;
	count += ft_putstr("0x");
	count += ft_ptr_hex(point);
	return (count);
}
