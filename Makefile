# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 16:28:21 by ttakami           #+#    #+#              #
#    Updated: 2022/10/28 18:33:55 by ttakami          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
CC			= cc
CFLAGS		= -Wall -Werror -Wextra

SRCS		= main.c exec_childproc.c utils.c
#SRCSB		=
OBJDIR		= obj
LIBFT		= libft/libft.a
OBJS		= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
#OBJSB		= $(addprefix $(OBJDIR)/, $(SRCSB:.c=.o))

#ifdef WITH_BONUS
#ALL_OBJS	= $(OBJSB)
#else
ALL_OBJS	= $(OBJS)
#endif

all:	directories $(NAME)

directories:
	@mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)
	@make -C libft clean

fclean:	clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re:	fclean all

#bonus:
#	@$(MAKE) WITH_BONUS=1 $(NAME)

#debug:		$(ALL_OBJS)
#	gcc --sanitize=leak -o $(NAME) $(ALL_OBJS) ./libft/libft.a

$(OBJDIR)/%.o:	%.c
	@[ -d $(OBJDIR) ]
	$(CC) -c $(CFLAGS) -o $@ $<

$(LIBFT):
	@make -C libft

$(NAME):	$(LIBFT) $(ALL_OBJS)
	gcc -o $(NAME) $(ALL_OBJS) $(LIBFT)

.PHONY:	all directories clean fclean re

#.PHONY:	all directories clean fclean re bonus debug

vpath %.c src