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
# include <limits.h>

// void	ft_putchar_fd(char c, int fd)
// {
// 	write (fd, &c, 1);
// }

// int	ft_atoi(const char *str)
// {
// 	int						i;
// 	int						fact;
// 	long					rst;

// 	i = 0;
// 	fact = 1;
// 	rst = 0;
// 	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
// 		i++;
// 	while (str[i] == '-' || (str[i] == '+'))
// 	{
// 		if (str[i] == '-')
// 			fact = fact * (-1);
// 		if (str[i + 1] == '+' || str[i + 1] == '-')
// 			return (0);
// 		i++;
// 	}
// 	while (str[i] >= 48 && str[i] <= 57)
// 	{
// 		rst = (rst * 10) + fact * (str[i] - 48);
// 		i++;
// 	}
// 	return (rst);
// }

// void	ft_putstr_fd(char *s, int fd)
// {
// 	int					i;

// 	// if (s == NULL)
// 	// 	return (NULL);
// 	i = 0;
// 	while (s[i])
// 	{
// 		write (fd, &s[i], 1);
// 		i++;
// 	}
// }

// void	ft_putnbr_fd(int n, int fd)
// {
// 	if (n == INT_MIN)
// 	{
// 		ft_putnbr_fd(n / 10, fd);
// 		ft_putchar_fd(8 + 48, fd);
// 	}
// 	else if (n < 0)
// 	{
// 		ft_putchar_fd('-', fd);
// 		ft_putnbr_fd(n * (-1), fd);
// 	}
// 	else
// 	{
// 		if (n > 9)
// 		{
// 			ft_putnbr_fd(n / 10, fd);
// 		}
// 		ft_putchar_fd(n % 10 + 48, fd);
// 	}
// }

void ft_handler(int num)
{
	static char c = 0;
	static int i = 0;


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

int main (int argc, char *argv[])
{
	int pid;
	struct  sigaction sa;
	struct  sigaction {
		union __sigaction_u __sigaction_u;  /* signal handler */
		sigset_t sa_mask;               /* signal mask to apply */
		int     sa_flags;               /* see signal options below */
     };

	pid =  getpid();
	printf("%d\n", pid);
	sa.sa_mask = SA_SIGINFO;
	// sigaction(SIGUSR1, ft_handler, NULL);
	// sigaction(SIGUSR2, ft_handler, NULL);
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	printf("Waiting for signal...\n");
	while(1)
		pause();
}














// int main (int argc, char *argv[])
// {
// 	int pid;
// 	struct sigaction signal;

// 	pid =  getpid();
// 	printf("%d\n", pid);
// 	signal.sa_sigaction = ft_handler;
// 	signal.sa_flags = SA_SIGINFO;
// 	sigaction(SIGUSR1, &signal, NULL);
// 	sigaction(SIGUSR2, &signal, NULL);
// 	// signal(SIGUSR1, handler);
// 	// signal(SIGUSR2, handler);
// 	while(1)
// 		pause();
// }
