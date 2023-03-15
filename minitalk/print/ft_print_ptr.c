/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khboutah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:28:28 by khboutah          #+#    #+#             */
/*   Updated: 2022/11/12 18:24:11 by khboutah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> 

static	int	ft_ptr_len(unsigned long long n)
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

int	ft_print_ptr(unsigned long long n)
{
	int	len;

	if (n == 0)
		return (write(1, "0x0", 3));
	len = 0;
	len += write(1, "0x", 2);
	ft_print_hex(n, 'x');
	len += ft_ptr_len(n);
	return (len);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
