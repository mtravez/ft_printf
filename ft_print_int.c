/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:26:38 by mtravez           #+#    #+#             */
/*   Updated: 2022/11/28 16:00:54 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_digits(int n)
{
	int	sum;

	sum = 0;
	while (n)
	{
		n = n / 10;
		sum++;
	}
	if (sum == 0)
		sum++;
	return (sum);
}

int	ft_putstr(char *string)
{
	if (!string)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(string, 1);
	return (ft_strlen(string));
}

int	ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	ft_putnbr_fd(n, 1);
	if (n < 0)
		count++;
	count += get_digits(n);
	return (count);
}

int	ft_put_unsigned(unsigned int n)
{
	unsigned int	div;
	int				count;

	count = 0;
	div = n;
	if (div < 10)
		count += ft_putchar(div + '0');
	else
	{
		count += ft_put_unsigned(div / 10);
		count += ft_putchar(div % 10 + '0');
	}
	return (count);
}
