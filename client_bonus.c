/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:36:40 by ztune             #+#    #+#             */
/*   Updated: 2021/08/26 18:36:42 by ztune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_8_signals(unsigned char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (((c >> i) & 1) == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_puterror(5);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_puterror(5);
		}
		usleep(USLEEP_TIME);
		i--;
	}
}

static void	send_32_signals(int c, int pid)
{
	int	i;

	i = 31;
	while (i >= 0)
	{
		if (((c >> i) & 1) == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_puterror(5);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_puterror(5);
		}
		usleep(USLEEP_TIME);
		i--;
	}
}

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
		{
			ft_putstr("\n", 1);
			exit(0);
		}
		bit = 0;
		byte = 0;
	}
}

static void	send_message(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_8_signals(str[i], pid);
		i++;
	}
	send_8_signals('\0', pid);
}

int	main(int argc, char **argv)
{
	pid_t	pid_client;
	int		pid_server;

	if (argc != 3)
		ft_puterror(2);
	pid_client = getpid();
	signal(SIGUSR1, get_1_signal);
	signal(SIGUSR2, get_1_signal);
	pid_server = ft_atoi(argv[1]);
	if (pid_server == 0)
		ft_puterror(3);
	if (argv[2][0] == '\0')
		ft_puterror(4);
	if (pid_client == pid_server)
		ft_puterror(6);
	send_32_signals(pid_client, pid_server);
	send_message(argv[2], pid_server);
	while (1 == 1)
		pause();
	return (0);
}
