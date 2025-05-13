# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/09 09:58:45 by mvillavi          #+#    #+#              #
#    Updated: 2025/05/09 09:58:47 by mvillavi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
#BONUS = pipex_bonus

SRC_DIR = src
#BONUS_DIR = bonus
OBJ_DIR = obj
#OBJ_BONUS_DIR = obj_bonus
INCLUDE_DIR = include
LIBFT_DIR = ./Libft

HEADER = $(INCLUDE_DIR)/pipex.h
#BONUS_HEADER = $(INCLUDE_DIR)/pipex_bonus.h

#Fuentes archivos
SRC_FILES = main.c 
#BONUS_FILES = 

# Rutas completas
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
#BSRCS = $(addprefix $(BONUS_DIR)/, $(BONUS_FILES))

# Objetos
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
#OBJS_BONUS = $(addprefix $(OBJ_BONUS_DIR)/, $(BONUS_FILES:.c=.o))

LIBFT = $(LIBFT_DIR)/libft.a

CC = cc -g
CFLAGS = -Wall -Werror -Wextra -I$(INCLUDE_DIR)
RM = rm -rf

# Colores
GREEN = \033[1;32m
BLUE = \033[1;34m
YELLOW = \033[1;33m
RED = \033[1;31m
RESET = \033[0m

all: $(NAME)

$(LIBFT):
	@echo "$(BLUE)-> Compilando Libft...$(RESET)"
	@make -C $(LIBFT_DIR)
	@make -C $(LIBFT_DIR) bonus

$(NAME): $(OBJS) $(LIBFT) $(HEADER) Makefile
	@echo "$(GREEN)✔ Compilando $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)
	@echo "$(GREEN)   Compilación completada!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compilando $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)


#bonus: $(BONUS)

#$(BONUS): $(OBJS_BONUS) $(LIBFT) $(BONUS_HEADER) Makefile
#	@echo "$(GREEN)✔ Compilando $(BONUS)...$(RESET)"
#	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(BONUS)
#	@echo "$(GREEN)   Compilación BONUS completada!$(RESET)"

#$(OBJ_BONUS_DIR)/%.o: $(BONUS_DIR)/%.c | $(OBJ_BONUS_DIR)
#	@echo "$(YELLOW)Compilando BONUS $<...$(RESET)"
#	@$(CC) $(CFLAGS) -c $< -o $@

#$(OBJ_BONUS_DIR):
#	@mkdir -p $(OBJ_BONUS_DIR)

clean:
	@echo "$(RED)  Limpiando objetos...$(RESET)"
	@make -C $(LIBFT_DIR) clean
	@$(RM) $(OBJ_DIR) 
#	$(OBJ_BONUS_DIR)

fclean: clean
	@echo "$(RED)  Borrando ejecutables...$(RESET)"
	@make -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME) 
#	$(BONUS)

re: fclean all

.PHONY: all clean fclean re 
#	bonus