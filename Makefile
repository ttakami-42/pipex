# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttakami <ttakami@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 16:28:21 by ttakami           #+#    #+#              #
#    Updated: 2023/03/01 16:24:27 by ttakami          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
DEBUG		= -g -fsanitize=address -fsanitize=undefined
LEAK		= -g -fsanitize=leak
SRCS		= main.c exec_childproc.c utils.c
#SRCSB		=
LIBFT		= libft/libft.a
OBJDIR		= obj
OBJS		= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
#OBJSB		= $(addprefix $(OBJDIR)/, $(SRCSB:.c=.o))

#ifdef WITH_BONUS
#ALL_OBJS	= $(OBJSB)
#else
ALL_OBJS	= $(OBJS)
#endif

all:	$(NAME)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	@[ -d $(OBJDIR) ]
	$(CC) -c $(CFLAGS) -o $@ $< $(HEADERPATH)

$(LIBFT):
	@make -C libft

$(NAME):	$(LIBFT) $(ALL_OBJS)
	gcc $(CFLAGS) -o $(NAME) $(ALL_OBJS) $(LIBFT)

clean:
	rm -rf $(OBJDIR)
	@make -C libft clean

fclean:	clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re:	fclean all

debug: $(NAME)
	$(CC) $(CFLAGS) $(DEBUG) -o $(NAME) $(ALL_OBJS) $(LIBFT)

leak: $(NAME)
	$(CC) $(CFLAGS) $(LEAK) -o $(NAME) $(ALL_OBJS) $(LIBFT)

#bonus:
#	@$(MAKE) WITH_BONUS=1 $(NAME)

.PHONY:	all clean fclean re debug leak

#.PHONY:	all clean fclean re debug leak bonus

vpath %.c src