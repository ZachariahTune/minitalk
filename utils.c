/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:36:51 by ztune             #+#    #+#             */
/*   Updated: 2021/08/26 18:36:53 by ztune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(int c, int std)
{
	write(std, &c, 1);
}

void	ft_putstr(char *str, int std)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], std);
		i++;
	}
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", 1);
		return ;
	}
	if (n < 0 && n != -2147483648)
	{
		ft_putchar('-', 1);
		ft_putnbr(-n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(n + '0', 1);
	}
}

int	ft_atoi(const char *str)
{
	int			sign;
	long int	ret;

	sign = 1;
	ret = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str == '0')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		ret = ret * 10 + (*str - 48);
		str++;
	}
	return ((int)(ret * sign));
}

void	ft_puterror(int code)
{
	ft_putstr("Error: ", 2);
	if (code == 1)
		ft_putstr("Server neobhodimo zapuskat bez argumentov\n", 2);
	if (code == 2)
		ft_putstr("Neobhodimo peredat 2 argumenta (PID, Stroka)\n", 2);
	if (code == 3)
		ft_putstr("Neobhodimo peredat korrektniy PID\n", 2);
	if (code == 4)
		ft_putstr("Stroka dolzhna soderzhat minimum 1 simvol\n", 2);
	if (code == 5)
		ft_putstr("Nevozmozhno otpravit soobshenie na danniy PID\n", 2);
	if (code == 6)
		ft_putstr("Nevozmozhno otpravit soobshenie samomu sebe\n", 2);
	exit(1);
}
