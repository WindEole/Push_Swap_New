/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:47:11 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/17 13:52:21 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_arg
{
	int		ac;
	char	**av;
}			t_arg;

typedef struct s_var
{
	int	len_a;
	int	len_b;
	int	add;
	int	min;
	int	max;
	int	pos_first;
	int	pos_second;
	int	max_len;
}		t_var;

// 2_fct_check.c

int		ft_check_init_sort(int *s_a, t_var var);
int		ft_check_reverse_sort(int *s_a, t_var *var);
int		ft_check_dupl(t_arg *arg);
int		ft_check_minmax(t_arg *arg, int k);
//int		ft_check_sort(int *s_a, t_var var);

// 3_stack_parse.c

t_var	ft_init_var(int max_len);
void	ft_free_split(char **str);
int		ft_create_stack(t_arg *arg, t_var *var);

// 4_algo_to5.c

void	ft_algo_2_3(int *s_a, t_var *var);
void	ft_algo_4_5(int *s_a, int *s_b, t_var *var);

// 5_algo_500_1_global.c

int		ft_algo_big_numbers(int *s_a, int *s_b, t_var *var);
void	ft_loop_browse(int *s_a, int *s_b, int *index_sa, t_var *var);

// 5_algo_500_2_index.c

int		ft_create_index(int *s_a, int *s_b, t_var *var);
int		ft_create_new_index(int *s_a, t_var *var);

// 5_algo_500_3_move.c

void	ft_move_to_top_a(int *s_a, int *s_b, t_var *var);

// 5_algo_500_4_posb.c

int		ft_define_pos_in_b(int xa, int *s_b, t_var *var);

// instr_swap_push.c

void	ft_swap_a(int *s_a, t_var *var);
void	ft_swap_b(int *s_b, t_var *var);
void	ft_swap_ab(int *s_a, int *s_b, t_var *var);
void	ft_push_a(int *s_a, int *s_b, t_var *var);
void	ft_push_b(int *s_a, int *s_b, t_var *var);

// instr_rotate.c

void	ft_rotate_a(int *s_a, t_var *var);
void	ft_rotate_b(int *s_b, t_var *var);
void	ft_rotate_ab(int *s_a, int *s_b, t_var *var);
void	ft_rotate_ab_suite(int *s_b, t_var *var);

// instr_revrotate.c

void	ft_revrotate_a(int *s_a, t_var *var);
void	ft_revrotate_b(int *s_b, t_var *var);
void	ft_revrotate_ab(int *s_a, int *s_b, t_var *var);
void	ft_revrotate_ab_suite(int *s_b, t_var *var);

// instr_loops.c

void	ft_loop_rotate_a(int *s_a, t_var *var);
void	ft_loop_rotate_ab(int *s_a, int *s_b, t_var *var, int x);
void	ft_loop_revrotate_a(int *s_a, t_var *var, int pos_second);
void	ft_loop_revrotate_ab(int *s_a, int *s_b, t_var *var, int x);
void	ft_loop_rotate_b(int pos_in_b, int *s_b, t_var *var);

// Libft

long	ft_atoi(const char *s);
char	*ft_strdup(const char *s1);
char	**ft_split(const char *s, char c);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(const char *str);

#endif
