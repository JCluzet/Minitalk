/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcluzet <jcluzet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 00:13:29 by jcluzet           #+#    #+#             */
/*   Updated: 2021/08/13 23:51:55 by jcluzet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <sys/types.h>

typedef struct s_encoder
{
	char	c;
	size_t	size;
}		t_encoder;

typedef struct s_confirm
{
	char	nb;
}		t_confirm;

void	str_transmetter(char *pid_str, char *message);
int		ft_atoi(const char *str);
void	char_transmetter(int pid, char message);
void	send_sign(int pid, int nb);
void	ft_putchar(int c);
void	ft_putnbr(int nb);

#endif
