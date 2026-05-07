# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bamagere <bamagere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/05 17:22:35 by bamagere          #+#    #+#              #
#    Updated: 2026/01/14 12:28:35 by bamagere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CONFIG~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
NAME		= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g3
RM			= rm -rf
OBJS_DIR	= objects
LIBRARY		= libft.h
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PROGRESS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
TOTAL     = $(words $(SRCS))
BAR_WIDTH = 40
PROGFILE  = .progress
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~LIBRARY~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
SRCS	=	ft_atoi.c \
			ft_atoi_failed.c \
			ft_atoli.c \
			ft_atoll.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_free_tab.c \
			ft_gameover.c \
			ft_gamewon.c \
			ft_isalnum.c \
			ft_isalnum_str.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_is_whitespace.c \
			ft_itoa.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_lstsort_alpha.c \
			ft_lsttabcpy.c \
			ft_lst_tabdup.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_path_checker.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_puts.c \
			ft_puts_color.c \
			ft_puts_rainbow.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_split_charset.c \
			ft_realloc.c \
			ft_strchr.c \
			ft_strcmp.c \
			ft_strdup.c \
			ft_strindex.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strjoin_free.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strldup.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strndup.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strtok.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tabcpy.c \
			ft_tabsize.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_utoa_base.c

OBJS= $(SRCS:%.c=$(OBJS_DIR)/%.o)
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
.PHONY : all clean fclean re bonus
.SILENT:

all: $(NAME)

bonus: $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@$(RM) $(PROGFILE)

$(OBJS_DIR)/%.o: %.c $(LIBRARY) | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
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
	@echo "$(MAGENTA)|~~> Libft: directory cleaned. <~~|$(NC)"

re: fclean all
