# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dju <dju@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 17:49:14 by dju               #+#    #+#              #
#    Updated: 2021/05/26 18:55:39 by dju              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PW = push_swap
NAME_CH = checker

FILE_PW = push_swap
FILE_CH = checker
FILES = operator stack_func utils utils_str utils_arr get_next_line get_arg

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ./$(INCPATH)

SRCPATH = src/
INCPATH = includes/

SRC_PW = $(addprefix $(SRCPATH), $(addsuffix .c, $(FILE_PW)))
SRC_CH = $(addprefix $(SRCPATH), $(addsuffix .c, $(FILE_CH)))
SRCS = $(addprefix $(SRCPATH), $(addsuffix .c, $(FILES)))
OBJ_PW = $(SRC_PW:.c=.o)
OBJ_CH = $(SRC_CH:.c=.o)
OBJS = $(SRCS:.c=.o)

$(NAME_PW): $(OBJS) $(OBJ_PW)
	@$(CC) $(CFLAGS) -o $(NAME_PW) $(OBJS) $(OBJ_PW)

$(NAME_CH): $(OBJS) $(OBJ_CH)
	@$(CC) $(CFLAGS) -o $(NAME_CH) $(OBJS) $(OBJ_CH)

all: $(NAME_PW) $(NAME_CH)

clean:
	@rm -f $(OBJS) $(OBJ_CH) $(OBJ_PW)

fclean: clean
	@rm -f $(NAME_CH) $(NAME_PW)

re: fclean all

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)