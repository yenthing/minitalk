/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:32:22 by ynguyen           #+#    #+#             */
/*   Updated: 2023/01/02 19:39:39 by ynguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_hexcountlower(unsigned long long nb)
{
	if (nb < 10)
		ft_putchar(nb + 48);
	else if (nb < 16)
		ft_putchar(nb + 87);
	else
	{
		ft_hexcountlower(nb / 16);
		ft_hexcountlower(nb % 16);
	}
}

static void	ft_hexcountupper(unsigned long long nb)
{
	if (nb < 10)
		ft_putchar(nb + 48);
	else if (nb < 16)
		ft_putchar(nb + 55);
	else
	{
		ft_hexcountupper(nb / 16);
		ft_hexcountupper(nb % 16);
	}
}

static int	ft_hexcountmore(unsigned long long nb, int count)
{
	if (nb == 0)
		count++;
	while (nb != 0)
	{
		count++;
		nb /= 16;
	}
	return (count);
}

int	ft_hexcount(unsigned long long nb, const char *s)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (s[i] == 'p')
	{
		if (nb == 0)
		{
			write(1, "(nil)", 5);
			return (5);
		}
		count += ft_putchar('0');
		count += ft_putchar('x');
		ft_hexcountlower(nb);
	}
	if (s[i] == 'x')
		ft_hexcountlower(nb);
	if (s[i] == 'X')
		ft_hexcountupper(nb);
	return (ft_hexcountmore(nb, count));
}

// int	main(void)
// {
// 	ft_hexcount(14);
// 	ft_putchar(10);
// 	ft_hexcount(123);
// 	ft_putchar(10);
// 	ft_hexcount(4);
// 	ft_putchar(10);
// 	return (0);
// }
