/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khboutah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:52:21 by khboutah          #+#    #+#             */
/*   Updated: 2023/03/12 17:52:28 by khboutah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	unsigned int	num;
	int				i;
	int				np;

	np = 1;
	i = 0;
	num = 0;
	while ((str[i] == 8 && str[i] == 13) || str[i] == 32)
			i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			np = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(np * num));
}

void	seg_sender(char *bits, pid_t pid)
{
	int	i;

	i = 0;
	while (bits[i])
	{
		if (bits[i] == '0')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(880);
		i++;
	}
}

void	conv_to_bits(unsigned char c, pid_t pid)
{
	int	nb;
	int	i;
	int	tab[8];

	nb = (int)c;
	i = 0;
	while (i < 8)
	{
		if (nb % 2 != 0)
			tab[i] = 1;
		else
			tab[i] = 0;
		nb /= 2;
		i++;
	}
	i = 0;
	while (i < 8)
	{
		usleep(870);
		if (tab[i] == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
	}
}

void	handle_sgnlnal(int sgnl)
{
	sgnl = 0;
	ft_printf("everything have been printed\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	char	*text;
	int		i;
	pid_t	pid;

	sgnlnal(SIGUSR1, handle_sgnlnal);
	if (argc != 3)
	{
		ft_printf("n of args args == %i\n", argc);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	text = argv[2];
	i = 0;
	while (text[i])
		conv_to_bits(text[i++], pid);
	if (pid == -1)
	{
		ft_printf("wrong pid!");
		return (0);
	}
	conv_to_bits(0, pid);
	while (1)
		pause();
	return (0);
}
