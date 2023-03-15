/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khboutah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:58:44 by khboutah          #+#    #+#             */
/*   Updated: 2022/11/12 14:04:52 by khboutah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_print_ptr(unsigned long long ptr);
int		ft_printf(const char *str, ...);
int		ft_print_str(char *str);
int		ft_print_hex(unsigned long long n, char c);
int		ft_print_nb(int n);
int		ft_print_unsigned(unsigned int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(long long nbr, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif
