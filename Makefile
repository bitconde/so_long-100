# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mconde-s <mconde-s@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/11 20:46:49 by mconde-s          #+#    #+#              #
#    Updated: 2025/05/03 15:50:06 by mconde-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_PRINTF_NAME = ./ft_printf/libftprintf.a
MLX = ./minilibx-linux/libmlx_Linux.a
MLX_2 = ./minilibx-linux/libmlx.a
NAME = so_long

C_FILES = map.c \
          so_long.c\
		  graphics.c \
		  events.c \
		  events_utils.c \
		  map_utils.c \
		  graphics_utils.c \
		  ./get_next_line/get_next_line.c \
		  ./get_next_line/get_next_line_utils.c \
		  utils.c

O_FILES = ${patsubst %.c, %.o, ${C_FILES}}

MLX_FLAGS = -I ./minilibx-linux -L ./minilibx-linux -lmlx -lX11 -lXext

all: ${NAME}

${NAME}: ${O_FILES} ${FT_PRINTF_NAME} ${MLX} ${MLX_2}
	cc -g ${O_FILES} ${FT_PRINTF_NAME} ${MLX_FLAGS} -o ${NAME}

${FT_PRINTF_NAME}:
	@ make -C ./ft_printf

${MLX_2}:
	@ make -C ./minilibx-linux

${MLX}:
	@ make -C ./minilibx-linux

clean_ft_printf:
	@ make -C ./ft_printf fclean

clean: clean_ft_printf
	@ rm -f ${O_FILES}

fclean: clean
	@ rm -f ${NAME} ${MLX} ${MLX_2}

re: fclean all

%.o: %.c
	cc -c -g -Wall -Wextra -Werror -o $@ $<

.PHONY: all clean fclean re
