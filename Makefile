# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddutta <ddutta@student.42adel.org.au>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 19:53:54 by ddutta            #+#    #+#              #
#    Updated: 2023/10/25 17:05:50 by ddutta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLX_DIR = minilibx
MLX = $(MLX_DIR)/libmlx.a

SRC_DIR = src
OBJ_DIR = obj

SRCS = main \
	   init \
	   render \
	   events \
	   misc_utils \
	   string_utils \

SRCS := $(SRCS:%=%.c)
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

NAME = fractol
CC = cc
CFLAGS = -Wall -Werror -Wextra -I./
LDFLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(MLX):
	make -C $(MLX_DIR)

re: fclean all

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJS)

