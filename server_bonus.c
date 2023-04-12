/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 00:42:17 by abez-zir          #+#    #+#             */
/*   Updated: 2023/04/05 00:42:20 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

static void	ft_handler(int num, siginfo_t *siginfo, void *cn)
{
	static char	c;
	static int	i;
	static int	pid;

	(void)cn;
	if (!pid)
		pid = siginfo->si_pid;
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
		if (c == '\0')
			kill(pid, SIGUSR1);
		i = 0;
		c = 0;
	}
}

int	main(int argc, char *argv[])
{
	int						pid;
	struct sigaction		sa;

	(void)argc;
	(void)argv;
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	sa.sa_sigaction = ft_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr_fd("\n\nBONUS say : Waiting for signal...  ⏳ 📡 📶\n\n", 1);
	while (1)
		pause();
}
