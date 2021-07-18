/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathanlafarge <nathanlafarge@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 14:08:10 by nathanlafar       #+#    #+#             */
/*   Updated: 2021/07/17 20:04:22 by nathanlafar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	throw_error(char *str)
{
	printf("\nError\n%s", str);
	exit(-1);
}

int	ft_return(unsigned long res, int neg)
{
	if (res > 9223372036854775807)
	{
		if (neg == -1)
			return (0);
		else
			return (-1);
	}
	return (res * neg);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				neg;
	unsigned long	res;

	i = 0;
	res = 0;
	neg = 1;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\r' || str[i] == '\n'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57)
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (ft_return(res, neg));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
