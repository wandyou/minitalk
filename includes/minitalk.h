/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathanlafarge <nathanlafarge@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:07:37 by nathanlafar       #+#    #+#             */
/*   Updated: 2021/07/17 19:59:05 by nathanlafar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_str
{
    char c;
    int octet;
}   t_str;

void throw_error(char *str);
void ft_putchar(char c);
int	ft_return(unsigned long res, int neg);
int	ft_atoi(const char *str);

#endif