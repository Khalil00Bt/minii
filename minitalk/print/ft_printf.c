/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khboutah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:55:39 by khboutah          #+#    #+#             */
/*   Updated: 2022/11/12 18:23:35 by khboutah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static	int	ft_print(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

static	int	ft_type(va_list args, char type)
{
	int	print_len;

	print_len = 0;
	if (type == 'c')
		print_len += ft_print(va_arg(args, int));
	else if (type == 's')
		print_len += ft_print_str(va_arg(args, char *));
	else if (type == 'x' || type == 'X')
		print_len += ft_print_hex(va_arg(args, unsigned int), type);
	else if (type == 'p')
		print_len += ft_print_ptr(va_arg(args, unsigned long long));
	else if (type == 'i' || type == 'd')
		print_len += ft_print_nb(va_arg(args, int));
	else if (type == 'u')
		print_len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (type == '%')
		print_len += write(1, "%", 1);
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_len;

	i = 0;
	va_start(args, str);
	print_len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] != '\0')
				print_len += ft_type(args, str[i++ + 1]);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			print_len += 1;
		}
		i++;
	}
	va_end(args);
	return (print_len);
}
