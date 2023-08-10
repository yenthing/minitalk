/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynguyen <ynguyen@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:35:10 by ynguyen           #+#    #+#             */
/*   Updated: 2023/03/24 16:13:52 by ynguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_reciever(int sig, siginfo_t *si, void *context)
{
	static int	c;
	static int	bit;

	(void)context;
	if (sig == SIGUSR1)
		c += (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		bit = 0;
		c = 0;
	}
	kill(si->si_pid, SIGUSR1);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_sigaction = &ft_reciever;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_printf("%i\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
