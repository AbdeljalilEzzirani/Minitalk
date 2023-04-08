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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/types.h>
#include <limits.h>

void	ft_handler(int num, siginfo_t *siginfo, void *cn)
{
	static unsigned char		c = 0;
	static int		i = 0;
	static int		pid = 0;

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

	pid = getpid();
	printf("%d\n", pid);
	sa.sa_sigaction = ft_handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL))
		kill(pid, SIGUSR1);
	sigaction(SIGUSR2, &sa, NULL);
	printf("Waiting for signal...\n");
	while (1)
		pause();
}
