# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: linux-babass <linux-babass@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/05 16:10:00 by linux-babas       #+#    #+#              #
#    Updated: 2025/12/06 00:25:48 by linux-babas      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CONFIG~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
NAME		= libgnl.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g3
RM			= rm -rf
OBJS_DIR	= objects
LIBRARY		= get_next_line_bonus.h
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PROGRESS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
TOTAL     = $(words $(SRCS))
BAR_WIDTH = 40
PROGFILE  = .progress
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~LIBRARY~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
SRCS		= get_next_line_bonus.c
INCLUDES    = -I. -I../libft
OBJS		= $(SRCS:%.c=$(OBJS_DIR)/%.o)
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~COLORS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
BLACK		= \033[1;30m
RED			= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
MAGENTA		= \033[0;35m
CYAN		= \033[0;36m
NC			= \033[0m
BOLD_RED	= \033[1;31m
BOLD_Y		= \033[1;33m
BOLD_MAG	= \033[1;35m
FLASH_Y		= \033[5;33m
FLASH_MAG	= \033[5;35m
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~DIRECTIVES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
.PHONY : all clean fclean re
.SILENT:

all: $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@$(RM) $(PROGFILE)

$(OBJS_DIR)/%.o: %.c $(LIBRARY) | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf . >> $(PROGFILE); \
	count=$$(wc -c < $(PROGFILE) 2>/dev/null || echo 0); \
	total=$(TOTAL); \
	if [ $$total -le 0 ]; then total=1; fi; \
	percent=$$(( 100 * $$count / $$total )); \
	filled=$$(( $(BAR_WIDTH) * $$percent / 100 )); \
	if [ $$percent -ge 100 ]; then filled=$(BAR_WIDTH); percent=100; fi; \
	empty=$$(( $(BAR_WIDTH) - $$filled )); \
	printf "\r$(BOLD_Y)Compiling:$(NC) ["; \
	i=0; while [ $$i -lt $$filled ]; do printf '#'; i=$$((i+1)); done; \
	i=0; while [ $$i -lt $$empty ]; do printf '-'; i=$$((i+1)); done; \
	printf "] %s%% (%s/%s)" $$percent $$count $$total; \
	if [ $$count -eq $$total ]; then printf "\n"; fi

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	@echo "$(MAGENTA)|~~> $(BOLD_MAG)$(NAME)$(MAGENTA): built  <~~|$(NC)"
	@$(RM) $(PROGFILE)

clean:
	@$(RM) -r $(OBJS_DIR) $(PROGFILE)

fclean: clean
	@$(RM) $(NAME)
	@echo "$(MAGENTA)|~~> GNL: directory cleaned. <~~|$(NC)"

re: fclean all
