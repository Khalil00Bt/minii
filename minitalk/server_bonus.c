/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khboutah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:52:49 by khboutah          #+#    #+#             */
/*   Updated: 2023/03/12 17:52:51 by khboutah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

typedef struct s_serv
{
	int		num;
	int		global;
	int		n_of_ones;
	char	tab[4];
	int		counter;
	int		i;
}				t_serv;

static int	g_get_c_pid = 0;

int	ft_power(int n)
{
	int	num;

	if (n == 0)
		return (1);
	if (n == 1)
		return (2);
	num = 2;
	while (n > 1)
	{
		num *= 2;
		n--;
	}
	return (num);
}

int	ft_calcul_ones(int num)
{
	int	i;

	i = 0;
	if (num > 239)
		return (4);
	if (num > 223)
		return (3);
	if (num > 191)
		return (2);
	if (num > 127)
		return (1);
	return (0);
}

void	handle_signal2(t_serv *vars)
{
	if (vars->global == 8)
	{
		if (vars->n_of_ones == 0)
			vars->n_of_ones = ft_calcul_ones(vars->num);
		if (vars->num == 0)
		{
			kill(g_get_c_pid, SIGUSR1);
			write(1, "\n", 1);
		}
		vars->tab[vars->i] = vars->num;
		if (vars->n_of_ones)
			vars->n_of_ones--;
		vars->i++;
		if (!vars->n_of_ones)
		{
			vars->tab[vars->i + 1] = 0;
			write(1, vars->tab, vars->i);
			vars->i = 0;
		}
		vars->global = 0;
		vars->num = 0;
	}
}

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static t_serv	vars;

	context = 0;
	if (g_get_c_pid != info->si_pid)
	{
		vars.global = 0;
		g_get_c_pid = info->si_pid;
		vars.n_of_ones = 0;
		vars.num = 0;
		vars.i = 0;
	}
	vars.num += (signal - 30) * ft_power(vars.global);
	vars.global++;
	handle_signal2(&vars);
}

int	main(int ac, char **av)
{
	struct sigaction	act;

	(void)**av;
	if (ac == 1)
	{
		act.sa_sigaction = handle_signal;
		act.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		ft_printf("PID: %d\n", getpid());
		while (1)
			pause();
	}
	else
	{
		ft_printf("server: unexpected error.\n");
		exit(EXIT_FAILURE);
	}	
	return (0);
}
