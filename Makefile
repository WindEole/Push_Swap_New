# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iderighe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/09 11:35:21 by iderighe          #+#    #+#              #
#    Updated: 2021/11/18 17:47:41 by iderighe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	=	push_swap

SRCS	=	1_main_arg_check.c \
			2_fct_check.c \
			3_stack_parse.c \
			4_algo_to5.c \
			5_algo_500_1_global.c \
			5_algo_500_2_index.c \
			5_algo_500_3_move.c \
			5_algo_500_4_posb.c \
			instr_swap_push.c \
			instr_rotate.c \
			instr_revrotate.c \
			instr_loops.c \
			lib_utils.c \
			lib_utils_split.c \

OBJ		=	$(SRCS:.c=.o)

CC		=	clang

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror


all		:	$(NAME)

%.o		:	%.c
			$(CC) $(CFLAGS) -o $@ -c $<

$(NAME)	:	$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean	:	
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all fclean clean re
