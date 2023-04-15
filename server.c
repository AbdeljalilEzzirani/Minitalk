/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:38:27 by abez-zir          #+#    #+#             */
/*   Updated: 2023/03/21 22:14:08 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

void	ft_handler(int num, siginfo_t *siginfo, void *cn)
{
	static unsigned char			c;
	static int						i;
	static int						pid;

	(void)cn;
	if (pid != (siginfo->si_pid))
	{
		pid = siginfo->si_pid;
		c = 0;
		i = 0;
	}
	if (num == SIGUSR1)
		c = c + (1 << i);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}	

int	main(int argc, char *argv[])
{
	int						pid;
	struct sigaction		sa;

	(void)argv;
	if (argc == 1)
	{
		pid = getpid();
		ft_putnbr_fd(pid, 1);
		sa.sa_sigaction = ft_handler;
		sa.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		ft_putstr_fd("\n\nWaiting for signal...  ⏳ 📡 📶\n\n", 1);
		while (1)
			pause();
	}
	else
		ft_putstr_fd("ERROR invalid argument\n", 2);
}
