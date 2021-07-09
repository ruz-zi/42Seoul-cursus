# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dju <dju@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/13 17:36:17 by dju               #+#    #+#              #
#    Updated: 2021/03/29 18:04:45 by dju              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wextra -Wall -Werror -I.

NAME = libftprintf.a
SRCS = ft_printf.c print_csp.c print_diux.c print_arg.c
OBJS = $(SRCS:.c=.o)

BONUS = ft_printf_bonus.c print_csp_bonus.c print_diuxX_bonus.c print_arg_bonus.c
B_OBJ = $(BONUS:.c=.o)

$(NAME): $(OBJS)
	make all -C libft/
	cp libft/libft.a $(NAME)
	ar rcv $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS) $(BONUS_O)
	make fclean -C libft/

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJS) $(B_OBJ)
	make all -C libft/
	cp libft/libft.a $(NAME)
	ar rcv $(NAME) $(OBJ) $(B_OBJ)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
