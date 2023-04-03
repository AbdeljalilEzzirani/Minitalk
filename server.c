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

static void ft_handler(int num, siginfo_t *info, void*d)
{
	// (void)info;
	(void)d;
	static char c = 0;
	static int bt = 0;
	
	if (num == SIGUSR1)
		c = c + (1 << bt);
	bt++;
	if (bt == 8)
	{
		if (c != '\0')
			write(1, &c, 1);
		c = 0;
		bt = 0;
	}
}

int main (int argc, char *argv[])
{
	int pid;
	struct sigaction signal;

	pid =  getpid();
	printf("%d\n", pid);
	signal.sa_sigaction = ft_handler;
	signal.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	// signal(SIGUSR1, handler);
	// signal(SIGUSR2, handler);
	while(1)
		pause();
}
