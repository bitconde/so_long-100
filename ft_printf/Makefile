# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mconde-s <mconde-s>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 17:45:12 by mconde-s          #+#    #+#              #
#    Updated: 2024/11/12 15:48:54 by mconde-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

 NAME = libftprintf.a

C_FILES = ft_char.c \
          ft_format.c\
          ft_hexa_max.c\
          ft_hexa_min.c\
          ft_num.c \
          ft_point.c \
          ft_printf.c\
          ft_str.c\
          ft_unsig_num.c\

O_FILES = ${patsubst %.c, %.o, ${C_FILES}}


all: ${NAME}

clean:

	@ rm -f $(O_FILES)

fclean: clean
	@ rm -f ${NAME}

re: fclean all
${NAME}: ${O_FILES}
	ar -rsc ${NAME} $?

%.o: %.c
	cc -c -g -Wall -Wextra -Werror $?

.PHONY: all clean fclean re