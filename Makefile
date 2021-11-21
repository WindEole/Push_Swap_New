# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iderighe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/09 11:35:21 by iderighe          #+#    #+#              #
#    Updated: 2021/11/21 19:15:21 by iderighe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	=	push_swap

NAME_C	=	checker

SRCS	=	1_main.c \
			2_fct_check.c \
			3_stack_parse.c \
			4_algo_to5.c \
			5_algo_500_1_global.c \
			5_algo_500_2_tri.c \
			free.c \
			instr_swap_push.c \
			instr_rotate.c \
			instr_revrotate.c \
			instr_loops.c \
			instr_list.c \
			lib_utils.c \
			lib_utils_split.c \
			lib_utils_strjoin.c \

SRCS_C	=	bonus/1_main.c \
			bonus/2_fct_check.c \
			bonus/3_stack_parse.c \
			bonus/5_algo_500_1_list.c \
			bonus/free.c \
			bonus/instr_swap_push.c \
			bonus/instr_rotate.c \
			bonus/instr_revrotate.c \
			bonus/instr_list.c \
			bonus/lib_utils.c \
			bonus/lib_utils_split.c \
			bonus/lib_utils_strjoin.c \
			bonus/get_next_line.c \
			bonus/get_next_line_utils.c \

OBJ		=	$(SRCS:.c=.o)

OBJ_C	=	$(SRCS_C:.c=.o)

CC		=	clang

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror #-fsanitize=address -g3


all		:	$(NAME)

bonus	:	$(NAME_C)

full	:	$(NAME) $(NAME_C)

%.o		:	%.c
			$(CC) $(CFLAGS) -o $@ -c $<

$(NAME)	:	$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

$(NAME_C):	$(OBJ_C)
			$(CC) $(CFLAGS) -o $(NAME_C) $(SRCS_C)

clean	:	
			$(RM) $(OBJ) $(OBJ_C)

fclean	:	clean
			$(RM) $(NAME) $(NAME_C)

re		:	fclean all

.PHONY	:	all fclean clean re bonus full
