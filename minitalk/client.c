/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khboutah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:52:09 by khboutah          #+#    #+#             */
/*   Updated: 2023/03/12 17:52:16 by khboutah         ###   ########.fr       */
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

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	str = (char *)malloc(i + 1);
	if (!str)
		return (0);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

void	segs_sender(char *bits, pid_t pid)
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
	char	*str;
	int		i;
	int		num;

	i = 0;
	num = (int)c;
	str = ft_strdup("00000000\0");
	if (!str)
		return ;
	while (i < 8)
	{
		if (num % 2 != 0)
			str[7 - i] = '1';
		num /= 2;
		i++;
	}
	segs_sender(str, pid);
	free(str);
}

int	main(int argc, char **argv)
{
	char	*text;
	int		i;
	pid_t	pid;

	if (argc != 3)
	{
		ft_printf("n of args args == %i\n", argc);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	text = argv[2];
	i = 0;
	if (pid == -1)
	{
		ft_printf("wrong pid!");
		return (0);
	}
	while (text[i])
	{
		conv_to_bits(text[i], pid);
		i++;
	}
	conv_to_bits(0, pid);
	return (0);
}
