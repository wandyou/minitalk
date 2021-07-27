/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathanlafarge <nathanlafarge@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:37:28 by nathanlafar       #+#    #+#             */
/*   Updated: 2021/07/27 22:41:40 by nathanlafar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static t_str	g_message;

void	addzero(int code)
{
	code = 0;
	(void)code;
	g_message.c += 0 << g_message.octet;
	g_message.octet++;
}

void	addone(int code)
{
	code = 0;
	(void)code;
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
	signal(SIGUSR2, addone);
	signal(SIGUSR1, addzero);
	while (1)
	{
		pause();
		if (g_message.octet >= 7)
		{
			ft_putchar(g_message.c);
			g_message.octet = 0;
			g_message.c = 0;
		}
	}
}
