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

#include "Minitalk.h"

static int	function(char ch, int pid)
{
	int				i;

	i = 0;
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
		i++;
		usleep(800);
	}
	return (1);
}

static void	print_msg_confirmation(int pid)
{
	if (signal(pid, print_msg_confirmation))
		ft_putstr_fd("\n\n✅ Mission accomplished 👍 👊 \n", 1);
	else
		ft_putstr_fd("🚨 The mission failed 👎 'signal return -1'\n", 1);
}

int	main(int argc, char *argv[])
{
	int				j;
	int				pid;

	pid = ft_atoi(argv[1]);
	j = 0;
	if (argc == 3)
	{
		print_msg_confirmation(pid);
		while (argv[2][j])
		{
			if (function(argv[2][j], pid) == 0)
				return (0);
			j++;
		}
	}
	else
		ft_putstr_fd("⛔BONUSERROR🚫maximum argument input more than -> 3\n", 1);
	return (0);
}
