/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:35:10 by ztune             #+#    #+#             */
/*   Updated: 2021/08/26 18:35:13 by ztune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	get_1_signal(int sigusr)
{
	static int	bit;
	static int	byte;

	if (sigusr == SIGUSR1)
		byte += 1 << (7 - bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar(byte, 1);
		if (byte == '\0')
			ft_putstr("\n", 1);
		bit = 0;
		byte = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc == 1 && argv[0][2] == 's')
	{
		pid = getpid();
		ft_putstr("Server PID = ", 1);
		ft_putnbr(pid);
		ft_putstr("\n", 1);
		signal(SIGUSR1, get_1_signal);
		signal(SIGUSR2, get_1_signal);
		while (1 == 1)
			pause();
	}
	else
		ft_puterror(1);
	return (0);
}
