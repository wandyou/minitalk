/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathanlafarge <nathanlafarge@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:37:42 by nathanlafar       #+#    #+#             */
/*   Updated: 2021/07/24 14:26:34 by nathanlafar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_message(int pid, char *str)
{
	int	i;
	int	octet;

	i = 0;
	while (str[i])
	{
		octet = 0;
		while (octet < 7)
		{
			if ((str[i] >> octet) & 1)
			{
				if(kill(pid, SIGUSR2) == -1)
					ft_putchar('2');
			}
			else
			{
				if(kill(pid, SIGUSR1) == -1)
					ft_putchar('1');
			}
			octet++;
			usleep(500);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc < 3)
		throw_error("Too few arguments on client");
	send_message(ft_atoi(argv[1]), argv[2]);
}
