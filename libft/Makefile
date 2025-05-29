# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 19:36:32 by bnespoli          #+#    #+#              #
#    Updated: 2024/09/10 01:59:10 by bnespoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

#List of source files
C_FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
 ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c get_next_line_bonus.c \
get_next_line_utils.c ft_printf_utils.c ft_printf.c ft_atol.c

#Define the directory for *.o files
OBJS_DIR = Objects

#Places each object filen the "Objects" directory while its created
OBJS_FILES = $(addprefix $(OBJS_DIR)/, $(C_FILES:.c=.o))

#Compiler flags
C_FLAGS = -Wall -Wextra -Werror -g

#Main target/command
$(NAME) : all

all: $(OBJS_FILES)
	@ echo Lib ready!

#Rule to compile and organize
$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	@ cc $(C_FLAGS) -c $< -o $@
	@ ar -rcs $(NAME) $@

#Create the "Objects" directory
$(OBJS_DIR):
	@ mkdir -p $(OBJS_DIR)

#Clean target
clean:
	@ rm -rf $(OBJS_DIR)
	@ echo Objects Directory removed!

#Full clean target
fclean: clean
	@ rm -f $(NAME)
	@ echo Lib removed!

re: fclean all

.PHONY: all clean fclean re