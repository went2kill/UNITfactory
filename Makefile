# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrobotko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/08 19:01:12 by yrobotko          #+#    #+#              #
#    Updated: 2017/08/08 19:01:21 by yrobotko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

G = gcc

FLAG = -Wall -Wextra -Werror

SRC =   magic_for_cc.c \
	magic_for_ddi.c \
	magic_for_oo.c \
	magic_for_p.c \
	magic_for_ss.c \
	magic_for_uu.c \
	magic_for_xx.c \
	part1.c \
	part2.c \
	part3.c \
	ft_printf.c \

HDR = ft_printf.h

OBJ = $(SRC:.c=.o)

DEL = rm -f

all: $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	ar -cru $(NAME) $(OBJ) libft/*.o
	ranlib $(NAME)
%.o: %.c
	$(G) $(CFLAGS) -c -o $@ $<
clean:
	$(DEL) $(OBJ)
	$(DEL) libft/*.o
fclean: clean
	$(DEL) $(NAME)
re:
	$(DEL) $(NAME)
	make $(NAME)
