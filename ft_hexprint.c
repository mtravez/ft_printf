/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:51:54 by mtravez           #+#    #+#             */
/*   Updated: 2022/11/28 15:45:17 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static int	get_digits_hex(unsigned int n)
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

static void	ft_print_hex(unsigned int n, char uplo)
{
	if (n >= 16)
	{
		ft_print_hex(n / 16, uplo);
		n = (n % 16);
	}
	if (n > 9)
		ft_putchar_fd(uplo + (n % 10), 1);
	else
		ft_putchar_fd(n + '0', 1);
}

int	ft_hexprint(unsigned int n, char uplo)
{
	ft_print_hex(n, uplo);
	return (get_digits_hex(n));
}
