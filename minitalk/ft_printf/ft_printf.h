/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:37:51 by ynguyen           #+#    #+#             */
/*   Updated: 2023/01/02 19:48:23 by ynguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_hexcount(unsigned long long nb, const char *s);
int	ft_numbercount(long long n);

#endif
