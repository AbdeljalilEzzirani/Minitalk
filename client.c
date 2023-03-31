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


int main (int argc, char *argv[])
{
    int i;

    i = 0;
    int pid = atoi(argv[1]);
    while (i < 8)
    {
        if (((*argv[2] >> i) & 1) == 1)
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