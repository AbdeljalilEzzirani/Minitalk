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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/types.h>
#include <limits.h>

void	ft_handler(int num, siginfo_t *siginfo, void *c)
{
	static unsigned char								l;
	static int								i = 0;
	static int								pid = 0;

	(void)c;
	if (pid != (siginfo->si_pid))
	{
		pid = siginfo->si_pid;
		l = 0;
		i = 0;
	}
	if (num == SIGUSR1)
		l = l + (1 << i);
	i++;
	if (i == 8)
	{
		write(1, &l, 1);
		i = 0;
		l = 0;
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
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (sigaction)
		kill(pid, SIGUSR2);
	printf("Waiting for signal...\n");
	while (1)
		pause();
}
