# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 15:00:50 by mtravez           #+#    #+#              #
#    Updated: 2022/11/29 11:45:15 by mtravez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

SRC=ft_hexprint.c \
	ft_print_int.c \
	ft_print_ptr.c \
	ft_printf.c

LIBSTUFF=libft/ft_putchar_fd.c \
		libft/ft_putnbr_fd.c \
		libft/ft_strlen.c	\
		libft/ft_isprint.c \
		libft/ft_putstr_fd.c	

OBJ=ft_hexprint.o \
	ft_print_int.o \
	ft_printf.o

LIBOBJ=ft_putchar_fd.o \
		ft_putnbr_fd.o	\
		ft_strlen.o \
		ft_print_ptr.o \
		ft_isprint.o \
		ft_putstr_fd.o	

FLAGS= -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@cc -c $(SRC) $(LIBSTUFF) $(FLAGS)
	@ar rc $(NAME) $(OBJ) $(LIBOBJ)

clean:
	@/bin/rm -f $(OBJ) $(LIBOBJ)

fclean: clean
	@/bin/rm -f $(NAME) a.out

re: fclean all
