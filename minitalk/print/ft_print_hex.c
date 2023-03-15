/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khboutah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:36:43 by khboutah          #+#    #+#             */
/*   Updated: 2022/11/13 20:36:46 by khboutah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_hex_len(unsigned int n)
{
	unsigned int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

static	void	ft_set_hex(unsigned long long n, char c)
{
	char	*hex;

	hex = "0123456789ABCDEF";
	if (c == 'x')
		hex = "0123456789abcdef";
	if (n < 16)
		ft_putchar_fd (hex[n % 16], 1);
	else
	{
		ft_set_hex(n / 16, c);
		ft_set_hex(n % 16, c);
	}
}

int	ft_print_hex(unsigned long long n, char c)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_set_hex(n, c);
	return (ft_hex_len(n));
}
