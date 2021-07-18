/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathanlafarge <nathanlafarge@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:37:28 by nathanlafar       #+#    #+#             */
/*   Updated: 2021/07/18 18:39:16 by nathanlafar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static t_str	g_message;

void	addzero(void)
{
	g_message.c += 0 << g_message.octet;
	g_message.octet++;
}

void	addone(void)
{
	g_message.c += 1 << g_message.octet;
	g_message.octet++;
}

int	main(void)
{
	int	pid;

	g_message.octet = 0;
	g_message.c = 0;
	pid = getpid();
	printf("%d\n", pid);
	while (1)
	{
		signal(SIGUSR1, addzero);
		signal(SIGUSR2, addone);
		pause();
		if (g_message.octet == 8)
		{
			ft_putchar(g_message.c);
			g_message.octet = 0;
			g_message.c = 0;
		}
	}
}
