/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khboutah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:47:56 by khboutah          #+#    #+#             */
/*   Updated: 2022/11/12 10:49:37 by khboutah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_len_num(unsigned int n)
{
	unsigned int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static	void	ft_unsigned(unsigned int n)
{
	if (n <= 9)
		ft_putchar_fd(n + 48, 1);
	else
	{
		ft_unsigned(n / 10);
		ft_unsigned(n % 10);
		n /= 10;
	}
}

int	ft_print_unsigned(unsigned int n)
{
	ft_unsigned(n);
	return (ft_len_num(n));
}
