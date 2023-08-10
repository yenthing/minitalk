/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:40:18 by ynguyen           #+#    #+#             */
/*   Updated: 2022/11/23 19:49:15 by ynguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		count = 6;
	}
	else
		while (s[count])
			ft_putchar(s[count++]);
	return (count);
}
