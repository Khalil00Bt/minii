# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khboutah <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 18:04:59 by khboutah          #+#    #+#              #
#    Updated: 2023/03/11 18:05:04 by khboutah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT     = client
SERVER     = server
CLIENT_B   = client_bonus
SERVER_B   = server_bonus
PRINTF     = print/libftprintf.a

C_SRCS     = client.c
S_SRCS     = server.c
C_SRCS_B   = client_bonus.c
S_SRCS_B   = server_bonus.c

PRINTF_SRCS = print/ft_print_hex.c \
              print/ft_print_nb.c \
              print/ft_print_ptr.c \
              print/ft_print_str.c \
              print/ft_print_unsigned.c \
              print/ft_printf.c \

C_OBJS     = $(C_SRCS:.c=.o)
S_OBJS     = $(S_SRCS:.c=.o)
C_OBJS_B   = $(C_SRCS_B:.c=.o)
S_OBJS_B   = $(S_SRCS_B:.c=.o)

CC         = cc
CFLAGS     = -Wall -Wextra -Werror

all: both

both: $(CLIENT) $(SERVER) print/ft_printf.h

$(CLIENT): $(C_OBJS) $(PRINTF_SRCS)
		make -C print
		$(CC) $(CFLAGS) $(C_OBJS) $(PRINTF) -o $(CLIENT)

$(SERVER): $(S_OBJS) $(PRINTF_SRCS)
		$(CC) $(CFLAGS) $(S_OBJS) $(PRINTF) -o $(SERVER)

bonus: $(CLIENT_B) $(SERVER_B) 

$(CLIENT_B): $(C_OBJS_B) $(PRINTF_SRCS)
		make -C print
		$(CC) $(CFLAGS) $(C_OBJS_B) $(PRINTF) -o $(CLIENT_B)

$(SERVER_B): $(S_OBJS_B) $(PRINTF_SRCS)
		$(CC) $(CFLAGS) $(S_OBJS_B) $(PRINTF) -o $(SERVER_B)

clean:
		make clean -C print
		rm -f $(S_OBJS) $(C_OBJS) $(S_OBJS_B) $(C_OBJS_B)

fclean: clean
		make fclean -C print
		rm -f $(CLIENT) $(SERVER) $(CLIENT_B) $(SERVER_B)

re: fclean all
