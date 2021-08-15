/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 00:13:57 by jcluzet           #+#    #+#             */
/*   Updated: 2021/07/20 00:13:58 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minitalk.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	char		arr[12];
	int			c;
	long int	nbim;

	c = 0;
	nbim = nb;
	if (nbim == 0)
		ft_putchar('0');
	if (nbim < 0)
	{
		ft_putchar('-');
		nbim *= (-1);
	}
	while (nbim != 0)
	{
		arr[c] = ((nbim % 10) + '0');
		nbim /= 10;
		c++;
	}
	while ((c - 1) >= 0)
	{
		ft_putchar(arr[c - 1]);
		c--;
	}
}

int	ft_atoi(const char *str)
{
	int	neg;
	int	i;
	int	num;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}
