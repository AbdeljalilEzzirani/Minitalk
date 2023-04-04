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
	int j;

	i = 0;
	j = 0;
	int pid = atoi(argv[1]);
	if (argc == 3)
	{
	    while (argv[2][j])
	    {
	        while (i <= 7)
	        {
	            if (((argv[2][j] >> i) & 1) == 1)
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
	        j++;
			i = 0;
	    }
	}
}
