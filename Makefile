# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iderighe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/09 11:35:21 by iderighe          #+#    #+#              #
#    Updated: 2021/11/25 13:35:59 by iderighe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#*****************************************************************************#
#                              MAKEFILE PUSH_SWAP                             #
#*****************************************************************************#

NAME	=	push_swap

SRCS	=	1_main.c \
			2_fct_check.c \
			3_stack_parse.c \
			4_algo_to3.c \
			4_algo_to5.c \
			5_algo_500_1_global.c \
			5_algo_500_2_tri.c \
			free.c \
			instr_swap_push.c \
			instr_rotate.c \
			instr_revrotate.c \
			instr_loops.c \
			instr_list.c \
			instr_list_suite.c \
			lib_utils.c \
			lib_utils_split.c \
			lib_utils_strjoin.c \

OBJ		=	$(SRCS:.c=.o)

CC		=	clang

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror #-fsanitize=address -g3


all		:	$(NAME)

#full	:	$(NAME) $(NAME_C)

%.o		:	%.c
			$(CC) $(CFLAGS) -o $@ -c $<

$(NAME)	:	$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean	:	
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

#*****************************************************************************#
#                              MAKEFILE CHECKER                               #
#*****************************************************************************#

NAME_C	=	checker

SRCS_C	=	bonus/1_main.c \
			bonus/2_fct_check.c \
			bonus/3_stack_parse.c \
			bonus/5_algo_500_1_list.c \
			bonus/free.c \
			bonus/instr_list.c \
			bonus/instr_list_suite.c \
			bonus/lib_utils.c \
			bonus/lib_utils_split.c \
			bonus/lib_utils_strjoin.c \
			bonus/get_next_line.c \
			bonus/get_next_line_utils.c \

OBJ_C	=	$(SRCS_C:.c=.o)

bonus	:	$(NAME_C)

%.o		:	%.c
			$(CC) $(CFLAGS) -o $@ -c $<

$(NAME_C):	$(OBJ_C)
			$(CC) $(CFLAGS) -o $(NAME_C) $(SRCS_C)

bclean	:	
			$(RM) $(OBJ_C)

bfclean	:	bclean
			$(RM) $(NAME_C)

bre		:	bfclean bonus

#*****************************************************************************#
#                              MAKEFILE LES DEUX                              #
#*****************************************************************************#

full	:	all bonus

cclean	:
			$(RM) $(OBJ) $(OBJ_C)

cfclean	:	cclean
			$(RM) $(NAME) $(NAME_C)

fullre	:	cfclean full

.PHONY	:	all fclean clean re bonus bclean bfclean bre full cclean cfclean fullre
