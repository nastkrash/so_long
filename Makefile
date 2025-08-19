# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anakrash <anakrash@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/21 19:03:04 by anakrash          #+#    #+#              #
#    Updated: 2024/12/21 19:03:05 by anakrash         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = flood_fill.c is_map_valid.c key_handler.c read_map.c so_long.c get_next_line.c get_next_line_utils.c

OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
LIBFT = assets/libft/libft.a
CFLAGS = -Wall -Wextra -Werror
LIBMLX = assets/mini-libx/libmlx.a

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(LIBMLX) $(OBJ_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@ -lft -lmlx -lm -lX11 -lXext -Iassets/mini-libx -L./assets/libft -Lassets/mini-libx

$(LIBFT): 
	@make -C assets/libft

$(LIBMLX): 
	@make -C assets/mini-libx

$(OBJ_DIR):
	@mkdir -p $@


clean:
	@rm -rf $(OBJ_DIR)
	@echo removed $(OBJ_DIR) folder

fclean: clean
	@rm -rf $(NAME)
	@echo removed $(NAME)


re: fclean all

.PHONY: all clean fclean re

