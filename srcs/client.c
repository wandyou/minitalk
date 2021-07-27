/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathanlafarge <nathanlafarge@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:37:42 by nathanlafar       #+#    #+#             */
/*   Updated: 2021/07/27 22:42:49 by nathanlafar      ###   ########.fr       */
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
				if (kill(pid, SIGUSR2) > 0)
					throw_error("Erreur de signal");
			}
			else
			{
				if (kill(pid, SIGUSR1) > 0)
					throw_error("Erreur de signal");
			}
			octet++;
			usleep(100);
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
