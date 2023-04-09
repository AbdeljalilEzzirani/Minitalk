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

void	ft_putstr_fd(char *s, int fd)
{
	int					i;

	i = 0;
	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
}

int	ft_atoi(const char *str)
{
	int						i;
	int						fact;
	long					rst;

	i = 0;
	fact = 1;
	rst = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	while (str[i] == '-' || (str[i] == '+'))
	{
		if (str[i] == '-')
			fact = fact * (-1);
		if (str[i + 1] == '+' || str[i + 1] == '-')
			return (0);
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		rst = (rst * 10) + fact * (str[i] - 48);
		i++;
	}
	return (rst);
}

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
		usleep(700);
		i++;
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
		ft_putstr_fd("⛔ BONUS say : ERROR 🚫 maximum argument input more than -> 3\n", 1);
	return (0);
}
