/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathanlafarge <nathanlafarge@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:37:28 by nathanlafar       #+#    #+#             */
/*   Updated: 2021/07/17 20:32:13 by nathanlafar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static t_str message;

void addzero(int code)
{
    code = 0;
    message.c += 0 << message.octet;
    message.octet++;
}

void addone(int code)
{
    code = 0;
    message.c += 1 << message.octet;
    message.octet++;
}

int main()
{
    int pid;
    
    message.octet = 0;
    message.c = 0;
    pid = getpid();
    printf("%d\n", pid);
    while (1)
    {
        signal(SIGUSR1, addzero);
        signal(SIGUSR2, addone);
        pause();
        if (message.octet == 8)
        {
            ft_putchar(message.c);
            if (!message.c)
                ft_putchar('\n');
            message.octet = 0;
            message.c = 0;
        }
    }
}