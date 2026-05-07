# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/05 16:36:19 by linux-babas       #+#    #+#              #
#    Updated: 2026/05/04 17:14:00 by linux-babas      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CONFIG~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
MAKEFLAGS   += --no-print-directory
NAME        = so_long

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3
RM          = rm -rf
VAL			= valgrind --leak-check=full --show-leak-kinds=definite \
			--track-origins=yes
VALQ			= valgrind --leak-check=full --show-leak-kinds=definite \
			--track-origins=yes --quiet

MAPS		= maps
WMAPS		= maps/wrongs

SRC_DIR     = sources/mandatory
BONUS_DIR   = sources/bonus
OBJ_DIR     = objects

LIB_DIR     = lib
LIBFT_DIR   = $(LIB_DIR)/libft
PRINTF_DIR  = $(LIB_DIR)/printfs
GNL_DIR     = $(LIB_DIR)/gnl

MLX_DIR     = minilibx-linux
MLX_REPO    = https://github.com/42Paris/minilibx-linux.git
MLX_LIB     = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS   = -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz

LIBFT_LIB   = $(LIBFT_DIR)/libft.a
PRINTF_LIB  = $(PRINTF_DIR)/libftprintf.a
GNL_LIB		= $(GNL_DIR)/libgnl.a

INCLUDES	= -Isources -I$(SRC_DIR) \
			  -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(GNL_DIR) \
			  -I$(MLX_DIR)

INC_BONUS	= -Isources -I$(BONUS_DIR) \
			  -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(GNL_DIR) \
			  -I$(MLX_DIR)

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~SOURCES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
SRCS		= main.c \
			check_map.c \
			check_map_utils.c \
			check_map_utils_two.c \
			game_completion.c \
			game_control.c \
			game_utils.c \
			moves.c \
			window_draw.c \
			window_utils.c

SRCS_BONUS  = main_bonus.c \
			utils/animation_1_bonus.c \
			utils/animation_2_bonus.c \
			utils/checker_1_bonus.c \
			utils/checker_2_bonus.c \
			utils/checker_3_bonus.c \
			utils/flood_fill_bonus.c \
			utils/game_control_bonus.c \
			utils/game_rules_bonus.c \
			utils/handle_input_bonus.c \
			utils/time_utils_bonus.c \
			images/images_destroy_1_bonus.c \
			images/images_destroy_2_bonus.c \
			images/images_destroy_3_bonus.c \
			images/images_loader_1_bonus.c \
			images/images_loader_2_bonus.c \
			images/images_loader_3_bonus.c \
			images/images_loader_4_bonus.c \
			moves/moves_basic_bonus.c \
			moves/moves_monsters_1_bonus.c \
			moves/moves_monsters_2_bonus.c \
			moves/moves_monsters_3_bonus.c \
			moves/moves_monsters_4_bonus.c \
			moves/moves_power_1_bonus.c \
			moves/moves_power_2_bonus.c \
			moves/moves_power_3_bonus.c \
			window/window_1_init_bonus.c \
			window/window_2_update_bonus.c \
			window/window_3_utils_bonus.c \
			window/window_4_end_bonus.c \
			window/windraw_1_features_1_bonus.c \
			window/windraw_1_features_2_bonus.c \
			window/windraw_2_border_bonus.c \
			window/windraw_3_hud_bonus.c

SRC         = $(addprefix $(SRC_DIR)/,$(SRCS))
SRC_BONUS   = $(addprefix $(BONUS_DIR)/,$(SRCS_BONUS))

OBJS        = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS  = $(SRC_BONUS:$(BONUS_DIR)/%.c=$(OBJ_DIR)/%.o)

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~COLORS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
BLACK		= \033[1;30m
RED			= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
MAG			= \033[0;35m
CYAN		= \033[0;36m
NC			= \033[0m
BOLD_RED	= \033[1;31m
BOLD_Y		= \033[1;33m
BOLD_MAG	= \033[1;35m
FLASH_Y		= \033[5;33m
FLASH_MAG	= \033[5;35m
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~RULES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
.PHONY: all clean fclean re bonus rebonus fetchmlx cleanmlx
.SILENT:

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compilation mandatory
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compilation bonus
$(OBJ_DIR)/%_bonus.o: $(BONUS_DIR)/%_bonus.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC_BONUS) -c $< -o $@

#~~~~~~~~~~~~~~~~~~~~~~~~~ Libs sub-makes ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
$(LIBFT_LIB):
	@echo "$(YELLOW)## Building 'libft'$(NC)"
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF_LIB):
	@echo "$(YELLOW)## Building 'the printfs'$(NC)"
	@$(MAKE) -C $(PRINTF_DIR)

$(GNL_LIB):
	@echo "$(YELLOW)## Building 'gnl'$(NC)"
	@$(MAKE) -C $(GNL_DIR)

$(MLX_LIB):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "$(BOLD_RED)Error: MinilibX not found.$(NC)"; \
		echo "$(YELLOW)Please run: make fetchmlx$(NC)"; \
		exit 1; \
	fi
	@echo "$(YELLOW)## Building 'mlx'$(NC)"
	@$(MAKE) -C $(MLX_DIR)

fetchmlx:
	@if [ -d "$(MLX_DIR)" ]; then \
		echo "$(GREEN)MinilibX already exists.$(NC)"; \
	else \
		echo "$(YELLOW)## Cloning 'mlx'$(NC)"; \
		git clone $(MLX_REPO) $(MLX_DIR); \
	fi

fclean+: fclean
	@if [ -d "$(MLX_DIR)" ]; then \
		echo "$(YELLOW)## Removing 'MinilibX'$(NC)"; \
		$(RM) $(MLX_DIR); \
		echo "$(MAG)|~~> MinilibX deleted. <~~|$(NC)"; \
	else \
		echo "$(RED)MinilibX not found.$(NC)"; \
	fi

#~~~~~~~~~~~~~~~~~~~~~~~~~~ MANDATORY ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
$(NAME): $(LIBFT_LIB) $(PRINTF_LIB) $(GNL_LIB) $(MLX_LIB) $(OBJS)
	@echo "$(YELLOW)## Building: $(BOLD_Y)'$(NAME)' (mandatory)$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) \
		$(PRINTF_LIB) $(GNL_LIB) $(LIBFT_LIB) \
		$(MLX_FLAGS) -o $(NAME)
	@echo "$(MAG)|~~> $(BOLD_MAG)$(NAME)$(MAG) built <~~|$(NC)"
#~~~~~~~~~~~~~~~~~~~~~~~~~~ Bonus ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
bonus: $(LIBFT_LIB) $(PRINTF_LIB) $(GNL_LIB) $(MLX_LIB) $(OBJS_BONUS)
	@echo "$(YELLOW)## Building: $(BOLD_Y)'$(NAME)' (bonus)$(NC)"
	@$(CC) $(CFLAGS) $(OBJS_BONUS) \
		$(PRINTF_LIB) $(GNL_LIB) $(LIBFT_LIB) \
		$(MLX_FLAGS) -o $(NAME)
	@echo "$(MAG)|~~> $(BOLD_MAG)$(NAME) (with bonus)$(MAG) built <~~|$(NC)"
#~~~~~~~~~~~~~~~~~~~~~~~~~~ Cleaning ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
clean:
	@echo "$(YELLOW)## Launch: 'clean'$(NC)"
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@$(MAKE) -C $(GNL_DIR) clean
# 	@$(MAKE) -C $(MLX_LIB) clean
	@echo "$(MAG)|~~> Objects deleted. <~~|$(NC)"

fclean: clean
	@echo "$(YELLOW)## Launch: 'fclean'$(NC)"
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@$(MAKE) -C $(GNL_DIR) fclean
# 	@$(MAKE) -C $(MLX_LIB) fclean
	@echo "$(MAG)|~~> Root directory cleaned. <~~|$(NC)"

re: fclean all

rebonus: fclean bonus

bonus+: fetchmlx bonus
rebonus+: fetchmlx rebonus

+: fetchmlx all
