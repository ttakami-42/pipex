# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 16:28:21 by ttakami           #+#    #+#              #
#    Updated: 2023/03/31 12:10:01 by ttakami          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
CC			= cc
CFLAGS		= -Wall -Werror -Wextra

ifdef WITH_DEBUG
	CFLAGS	= -Wall -Werror -Wextra -g -fsanitize=address -fsanitize=undefined
endif

ifdef WITH_LEAK
	CFLAGS	= -Wall -Werror -Wextra -g -fsanitize=leak
endif

SRCS		= main.c exec_childproc.c utils.c
#SRCSB		=
LIBFTDIR	= libft
LIBFT		= $(addprefix $(LIBFTDIR)/, libft.a)
INC			= -Iinclude -I$(LIBFTDIR)
OBJDIR		= obj
OBJS		= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
#OBJSB		= $(addprefix $(OBJDIR)/, $(SRCSB:.c=.o))

#ifdef WITH_BONUS
#ALL_OBJS	= $(OBJSB)
#else
ALL_OBJS	= $(OBJS)
#endif

# color codes

RESET		= \033[0m
GREEN		= \033[32m
YELLOW		= \033[33m

# Check if object directory exists, build libft and then the Project

all:	$(NAME)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	@[ -d $(OBJDIR) ]
	@echo "$(YELLOW)      - Compiling :$(RESET)" $<
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(LIBFT):
	@make bonus --no-print-directory -sC $(LIBFTDIR)

$(NAME): $(LIBFT) $(OBJS)
	@echo "$(YELLOW)\n      - Building $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	@echo "$(GREEN)***   Project $(NAME) successfully compiled   ***\n$(RESET)"

clean:
	@echo "$(GREEN)***   Deleting all object from $(NAME)   ...   ***\n$(RESET)"
	@rm -rf $(OBJDIR)
	@make clean --no-print-directory -sC $(LIBFTDIR)
	@echo "done\n"

fclean: clean
	@echo "$(GREEN)***   Deleting executable file from $(NAME)   ...   ***\n$(RESET)"
	@rm -f $(NAME)
	@make fclean --no-print-directory -sC $(LIBFTDIR)
	@echo "done\n"

re: fclean all

debug: fclean
	@make --no-print-directory WITH_DEBUG=1
	@echo "$(GREEN)***   You can debug $(NAME)   ***\n$(RESET)"

leak: fclean
	@make --no-print-directory WITH_LEAK=1
	@echo "$(GREEN)***   You can see leaks $(NAME)   ***\n$(RESET)"

#bonus:
#	@make WITH_BONUS=1

.PHONY:	all clean fclean re debug leak

#.PHONY:	all clean fclean re debug leak bonus

vpath %.c src
