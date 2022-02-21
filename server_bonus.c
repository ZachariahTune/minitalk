/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:35:20 by ztune             #+#    #+#             */
/*   Updated: 2021/08/26 18:35:22 by ztune            ###   ########.fr       */
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
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(USLEEP_TIME);
		i--;
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

static int	put_client_pid(int pid, int *bit, int *byte)
{
	ft_putstr("From client ", 1);
	ft_putnbr(pid);
	ft_putstr(": ", 1);
	*bit = 0;
	*byte = 0;
	return (pid);
}

static void	get_1_signal(int sigusr)
{
	static int	bit;
	static int	byte;
	static int	pid;

	if (sigusr == SIGUSR1 && !pid)
		byte += 1 << (31 - bit);
	if (sigusr == SIGUSR1 && pid)
		byte += 1 << (7 - bit);
	bit++;
	if (bit == 32 && !pid)
		pid = put_client_pid(byte, &bit, &byte);
	if (bit == 8 && pid)
	{
		ft_putchar(byte, 1);
		if (byte == '\0')
		{
			ft_putstr("\n", 1);
			send_message("OK: soobshenie dostavleno", pid);
			pid = 0;
		}
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
