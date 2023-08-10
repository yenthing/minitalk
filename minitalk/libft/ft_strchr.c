/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:00:05 by ynguyen           #+#    #+#             */
/*   Updated: 2022/10/21 13:23:59 by ynguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	if (c >= 128)
		c %= 128;
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (0);
}
// int	main(void)
// {
// 	char c[] = "this is my imma";

// 	char *s = ft_strchr(c, 'm');
// 	printf("%s\n", s);
// 	return (0);
// }
