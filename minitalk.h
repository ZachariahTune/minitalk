/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 18:33:59 by ztune             #+#    #+#             */
/*   Updated: 2021/08/26 18:34:03 by ztune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# define USLEEP_TIME 100

void	ft_putchar(int c, int std);
void	ft_putstr(char *str, int std);
void	ft_putnbr(int n);
int		ft_atoi(const char *str);
void	ft_puterror(int code);

#endif
