/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbercount.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:30:35 by ynguyen           #+#    #+#             */
/*   Updated: 2023/01/02 16:19:40 by ynguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(unsigned long long nb)
{
	if (nb < 10)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

int	ft_numbercount(long long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		n *= -1;
	}
	if (n == 0)
		count++;
	ft_putnbr(n);
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}
