NAME = libft.a

SRCS = ./srcs/*.c

PATH_OBJS = ./objs/
OBJS = $(SRCS:%.c=$(PATH_OBJS)%.o)

PATH_INCLS = ./
INCLS = -I $(PATH_INCLS)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $@ $^
	@echo "Compiled."

clean:
	@rm -rf $(PATH_OBJS)
	@echo "Cleaned."

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
