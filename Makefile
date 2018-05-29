# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minakim <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/22 16:09:48 by minakim           #+#    #+#              #
#    Updated: 2018/05/22 17:16:54 by minakim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE = make -C
NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIB = libft/
HEADER = -I /includes

SRC = src/ft_printf.c\
	  src/check.c\
	  src/initiation.c\
	  src/trim.c\
	  src/specifier1.c\
	  src/specifier2.c\
	  src/specifier3.c\
	  src/print_format.c\
	#   src/jfj.c

OBJ = $(SRC:.c=.o)
OBJ_DIR = obj

LIBM = $(MAKE) $(LIB)
LIBR = $(MAKE) $(LIB) re
LIBC = $(MAKE) $(LIB) clean
LIBF = $(MAKE) $(LIB) fclean

all: $(NAME)

$(NAME):
	@$(LIBM)
	@$(CC) $(FLAGS) -c $(SRC) $(HEADER)
	@cp $(LIB)/libft.a $(NAME)
	@ar rcs $(NAME) *.o
	@ranlib $(NAME)
	@mkdir $(OBJ_DIR)
	@mv *.o $(OBJ_DIR)

clean:
	@$(LIBC)
	@/bin/rm -rf $(OBJ_DIR)

fclean:
	@$(LIBF)
	@/bin/rm -f $(NAME) *.a
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
