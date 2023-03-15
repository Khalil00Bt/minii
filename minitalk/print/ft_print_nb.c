/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khboutah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:26:26 by khboutah          #+#    #+#             */
/*   Updated: 2022/11/13 20:33:32 by khboutah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	long long	ft_nbr_len(int n)
{
	long long	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_print_nb(int n)
{
	ft_putnbr_fd(n, 1);
	return (ft_nbr_len(n));
}

void	ft_putnbr_fd(long long nbr, int fd)
{
	char		out;
	long long	nb;

	nb = nbr;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = nb * -1;
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		out = (nb % 10) + '0';
	}
	else
	{
		out = (nb % 10) + '0';
	}
	write(fd, &out, 1);
}
