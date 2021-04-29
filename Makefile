# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gneve <gneve@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/27 13:33:43 by gneve             #+#    #+#              #
#    Updated: 2021/04/27 14:44:38 by gneve            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc
# CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I./includes/ -I/usr/include

MLX = ./minilibx-linux/libmlx.a
MLXFL = $(dir ${MLX})
LDFLAGS += -L ${MLXFL} -lmlx

LDFLAGS += -lXext -lX11

LIBFT = ./libft/libft.a
LIBFTFL = $(dir ${LIBFT})
LDFLAGS += -L ${LIBFTFL} -lft
CFLAGS += -I./libft

###▼▼▼<src-updater-do-not-edit-or-remove>▼▼▼
# **************************************************************************** #
# **   Generated with https://github.com/lorenuars19/makefile-src-updater   ** #
# **************************************************************************** #

SRCS =\
	./srcs/main.c\
	./srcs/get_next_line.c\
	./srcs/get_next_line_utils.c\

HEADERS =\
	./includes/mlx.h\
	./includes/get_next_line.h\
	./includes/cube.h\

###▲▲▲<src-updater-do-not-edit-or-remove>▲▲▲

OBJS = $(SRCS:.c=.o)
VPATH += ./srcs


all: LIBFT MLX ${NAME}
	@printf ""

LIBFT :
	$(MAKE) -C ${LIBFTFL} $(MAKECMDGOALS)

MLX :
	$(MAKE) -C ${MLXFL} $(MAKECMDGOALS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

${NAME} : ${SRCS} ${HEADERS} ${OBJS}
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all
