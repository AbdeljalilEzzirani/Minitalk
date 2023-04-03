/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abez-zir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:38:14 by abez-zir          #+#    #+#             */
/*   Updated: 2023/03/21 17:38:17 by abez-zir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/wait.h>
#include <signal.h>
#include <sys/types.h>


static void	ft_bit_sender(int pid, char chara)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((chara & (1 << bit)) != 0)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write (2, "\e[033;0;31m→  PID not correct. ❌\e[0m\n", 47);
				exit(0);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write (2, "\e[033;0;31m→  PID not correct. ❌\e[0m\n", 47);
				exit(0);
			}
		}
		usleep(800);
		bit++;
	}
}

void	ft_send_message(int pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		ft_bit_sender(pid, msg[i]);
		i++;
	}
	ft_bit_sender(pid, '\n');
	ft_bit_sender(pid, '\0');
}


int main (int argc, char *argv[])
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (argc == 3)
    {
        // while (argv[2][j])
        // {
        //     while (i < 8)
        //     {
        //         if (((argv[2][j] >> i) & 1) == 1)
        //         {
        //             if (kill(pid, SIGUSR1) == -1)
        //                 return (0);
        //         }
        //         else
        //         {
        //             if (kill(pid, SIGUSR2) == -1)
        //                 return (0);
        //         }
        //         usleep(700);
        //         i++;
        //     }
        //     j++;
        int pid = atoi(argv[1]);
        ft_send_message(pid, argv[2]);
        // }
    }
}



















































    // char c = 'a';
    // int i;


    // i = 0;


    // while (i < 8)
    // {
    //     if (((c << 1) & 1) == 1)
    //     {
    //         kill(pid, SIGUSR1);
    //     }
    //     else
    //     {
    //         kill(pid, SIGUSR2);
    //     }
    //     usleep(700);
    //     i++;
    // }