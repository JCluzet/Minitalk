/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 00:13:41 by jcluzet           #+#    #+#             */
/*   Updated: 2021/08/13 23:55:08 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minitalk.h"

static t_confirm	g_confirm;

void	send_sign(int pid, int nb)
{
	if (nb == 1)
	{
		if (kill(pid, SIGUSR1) == -1)
			g_confirm.nb++;
	}
	if (nb == 0)
	{
		if (kill(pid, SIGUSR2) == -1)
			g_confirm.nb++;
	}
}

void	char_encoder(int pid, char message)
{
	int	index;

	index = 0;
	while (index < 7)
	{
		if ((message >> index) & 1)
			send_sign(pid, 0);
		else
			send_sign(pid, 1);
		usleep(100);
		index++;
	}
}

void	str_transmetter(char *pid_str, char *message)
{
	int	pid;
	int	i;

	i = 0;
	pid = ft_atoi(pid_str);
	while (message[i])
	{
		char_encoder(pid, message[i]);
		i++;
	}
	if (g_confirm.nb == 0)
		write(1, "Message successfully send\n", 27);
	else
		write(1, "Cannot send message, please check \
			the PID , or the status of server\n", 68);
}

int	main(int argc, char **argv)
{
	g_confirm.nb = 0;
	if (argc != 3)
	{
		write(1, "Error\nUsage : ./client [pid] [message]\n", 38);
		return (0);
	}
	str_transmetter(argv[1], argv[2]);
	return (0);
}
