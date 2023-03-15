# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khboutah <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 18:09:15 by khboutah          #+#    #+#              #
#    Updated: 2022/11/11 18:09:22 by khboutah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_print_hex.c ft_print_nb.c ft_print_ptr.c ft_print_str.c ft_print_unsigned.c ft_printf.c 
cc = cc
flags= -Wall -Wextra -Werror -g
OBJCT = $(SRC:%.c=%.o)
NAME = libftprintf.a

all :$(NAME)

$(NAME): $(OBJCT)

%.o : %.c ft_printf.h
	$(cc) $(flags) -c $<
	ar rc $(NAME) $@
clean:
	rm -rf $(OBJCT)
fclean : clean
	rm -rf $(NAME)
re : fclean $(NAME)
