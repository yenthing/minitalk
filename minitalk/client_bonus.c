/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynguyen <ynguyen@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:28:43 by ynguyen           #+#    #+#             */
/*   Updated: 2023/03/24 16:13:22 by ynguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int		g_recieved = 0;

void	ft_handshake(int sig)
{
	if (sig == SIGUSR1)
		g_recieved++;
}

void	ft_send_bits(char c, int pid)
{
	int	i;
	int	handshake;

	i = 0;
	while (i < 8)
	{
		handshake = g_recieved;
		if (c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		while (handshake == g_recieved)
			pause();
	}
}

void	ft_send(char *s, int pid)
{
	int	i;

	i = 0;
	while (s[i])
		ft_send_bits(s[i++], pid);
	ft_send_bits('\n', pid);
	if (g_recieved > 0)
		ft_printf("Server received %d bits / %d characters!\n", g_recieved,
			g_recieved >> 3);
	else
		write(2, "\033[31;1;4m\nError sending!\n", 23);
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		write(2, "Wrong usage\n", 13);
		return (0);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		write(2, "Wrong PID!", 11);
		return (0);
	}
	signal(SIGUSR1, &ft_handshake);
	ft_send(av[2], pid);
	return (0);
}
