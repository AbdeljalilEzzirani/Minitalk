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

void handler(int num)
{
	static char c = 0;
	static int i = 0;
	if (num == SIGUSR1)
		c = c + (1 << i);
	i++;
	if (i == 8)
		write(1, &c, 1);
}

int main (int argc, char *argv[])
{
	int pid;

	pid =  getpid();
	printf("%d\n", pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	// signal(SIGUSR2, handler);
	// signal(SIGUSR1, handler);
	// signal(SIGUSR2, handler);
	// signal(SIGUSR1, handler);
	// signal(SIGUSR1, handler);
	// signal(SIGUSR2, handler);
	// signal(SIGUSR2, handler);
	while(1)
		pause();
}
