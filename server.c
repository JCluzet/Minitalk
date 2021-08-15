/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jo@cluzet.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 00:13:49 by jcluzet           #+#    #+#             */
/*   Updated: 2021/07/20 00:14:30 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minitalk.h"

static t_encoder	g_encoder;

void	decoder(int sign)
{
	g_encoder.c += ((sign & 1) << g_encoder.size);
	g_encoder.size++;
	if (g_encoder.size == 7)
	{
		ft_putchar(g_encoder.c);
		g_encoder.c = 0;
		g_encoder.size = 0;
	}
}

int	main(int ac, char **av)
{
	g_encoder.c = 0;
	g_encoder.size = 0;
	if (ac != 1)
		write(1, "No parameters needed\n", 22);
	write(1, "PID : ", 7);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
	{
		signal (SIGUSR2, decoder);
		signal (SIGUSR1, decoder);
		pause();
	}
	(void)av;
	return (0);
}
