/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:52:30 by ynguyen           #+#    #+#             */
/*   Updated: 2023/01/02 19:54:26 by ynguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

static int	ft_identify(va_list args, const char *s, int i, int count)
{
	if (s[i] == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (s[i] == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (s[i] == 'd' || s[i] == 'i')
		count += ft_numbercount(va_arg(args, int));
	else if (s[i] == '%')
		count += ft_putchar('%');
	else if (s[i] == 'u')
		count += ft_numbercount(va_arg(args, unsigned int));
	else if (s[i] == 'p')
		count += ft_hexcount(va_arg(args, unsigned long long), s + i);
	else if (s[i] == 'x')
		count += ft_hexcount(va_arg(args, unsigned int), s + i);
	else if (s[i] == 'X')
		count += ft_hexcount(va_arg(args, unsigned int), s + i);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		count;
	int		i;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			count = ft_identify(args, s, i, count);
		}
		else
			count += write(1, &s[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	int	i;

// 	i = ft_printf("%x", "34");
// 	printf("%i", i);
// }
