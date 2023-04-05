/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 00:42:07 by abez-zir          #+#    #+#             */
/*   Updated: 2023/04/05 00:42:09 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/wait.h>
#include <signal.h>
#include <sys/types.h>

int	function(char ch, int pid)
{
	int				i;

	while (i <= 7)
	{
		if (((ch >> i) & 1) == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (0);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (0);
		}
		usleep(600);
		i++;
	}
	i = 0;
	return (0);
}

int	main(int argc, char *argv[])
{
	int				j;
	int				pid;

	pid = atoi(argv[1]);
	j = 0;
	if (argc == 3)
	{
		while (argv[2][j])
		{
			function(argv[2][j], pid);
			j++;
		}
	}
	return (0);
}
