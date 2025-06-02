# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/29 18:54:06 by bnespoli          #+#    #+#              #
#    Updated: 2025/06/02 18:14:27 by bnespoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := cub3D
CFLAGS      := -Wextra -Wall -Werror -g3 -O3 -fPIC -MMD -MP
MAKEFLAGS   += --silent

LIBMLX      := ./MLX42
LIBFT_PATH  := ./libft
LIBFT       := $(LIBFT_PATH)/libft.a
MLX_REPO    := https://github.com/codam-coding-college/MLX42.git

CC          := gcc
SRC_PATH    := src
OBJ_PATH    := objects

CFILES      := main.c \
                init/init.c \
                init/init_game.c \
                utils/utils.c \
                exit/free_memory.c \
                parsing/parsing.c \
                parsing/check_args.c \
                parsing/check_rgb.c \
                parsing/data_processing.c \
                parsing/map.c \
                parsing/check_path.c \
                parsing/map_utils.c \
                parsing/check_wall.c \
                parsing/tabs.c \
                parsing/parsing_utils.c \
                render/hooks.c \
                render/movements.c \
                render/images.c \
                render/draw_squares.c \
                render/wall.c \
                render/algorithm.c \
                render/update_image.c \
                render/draw_loop.c

SRCS        := $(addprefix $(SRC_PATH)/, $(CFILES))
OBJS        := $(addprefix $(OBJ_PATH)/, $(CFILES:%.c=%.o))
DEPS        := $(OBJS:.o=.d)

HEADERS     := -I ./includes -I ./MLX42/include
LIBS_MLX    := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

all: libmlx $(LIBFT) $(OBJ_PATH) $(NAME)

libmlx:
	@if [ ! -d "$(LIBMLX)" ]; then \
		echo "Cloning MLX42 repository..."; \
		git clone $(MLX_REPO) $(LIBMLX); \
	fi
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS_MLX) $(LIBFT) $(HEADERS) -o $(NAME) -lm
	@echo "The CUB3D has been compiled!"

clean:
	@rm -rf $(OBJ_PATH)
	@echo "Objects cleaned."

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBMLX)/build
	@make fclean -C $(LIBFT_PATH)
	@echo "Cleaning complete!"

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re libmlx