/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:47:11 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/23 12:33:23 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define GREY "\033[1;37m"
# define RESET "\033[0m"

typedef struct s_arg
{
	int		ac;
	char	**av;
}	t_arg;

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
}	t_var;

typedef struct s_dll
{
	int				arg;
	int				i;
	int				opa;
	int				opb;
	int				opr;
	int				opt;
	int				rev;
	int				revb;
	struct s_dll	*next;
	struct s_dll	*prev;
}	t_dll;

typedef struct s_adm
{
	struct s_dll	*head;
	struct s_dll	*tail;
}	t_adm;

// 2_fct_check.c

int		ft_check_init_sort(int *s_a, t_var var);
int		ft_check_reverse_sort(int *s_a, t_var *var);
int		ft_check_dupl(t_arg *arg);
int		ft_check_minmax(t_arg *arg, int k);
//int		ft_check_sort(int *s_a, t_var var);

// 3_stack_parse.c

t_var	ft_init_var(int max_len);
int		ft_create_stack(t_arg *arg, t_var *var);

// 4_algo_to5.c

void	ft_algo_2_3(int *s_a, t_var *var);
void	ft_algo_4_5(int *s_a, int *s_b, t_var *var);

// 5_algo_500_1_global.c

//int		ft_algo_big_numbers(int *s_a, int *s_b, t_var *var);
//void	ft_loop_browse(int *s_a, int *s_b, int *index_sa, t_var *var);
//int		ft_stack_to_list(int *s_a, int *s_b, t_var *var);

t_adm	*ft_list_init_b(t_adm *adm);
t_adm	*ft_list_init_a(t_adm *adm, t_dll *dll, int first);
int		ft_list_inser(t_adm *adm, int n);
int		ft_lstlen(t_adm *adm);
void	ft_create_index(t_adm *adm);

// 5_algo_500_2_tri.c

void	ft_tri(t_adm *adma, t_adm *admb, t_dll **now, int x);

/*
// 5_algo_500_2_index.c

//int		ft_create_index(int *s_a, int *s_b, t_var *var);

int		ft_create_new_index(int *s_a, t_var *var);

// 5_algo_500_3_move.c

void	ft_move_to_top_a(int *s_a, int *s_b, t_var *var);

// 5_algo_500_4_posb.c

int		ft_define_pos_in_b(int xa, int *s_b, t_var *var);*/

// free.c

void	ft_free_split(char **str);
void	ft_free_list(t_adm *adm);
int		ft_free_stack(t_adm **adm, t_arg *arg, int *s_a, int *s_b);

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

// instr_list.c

void	ft_rot(t_adm *adm, char *s);
void	ft_revrot(t_adm *adm, char *s);
void	ft_swap(t_adm *adm, char *s);
void	ft_push(t_adm *lstfrom, t_adm *lstto, char *s);

// instr_list_suite.c

void	ft_rr(t_adm *adma, t_adm *admb);
void	ft_rrr(t_adm *adma, t_adm *admb);
void	ft_ss(t_adm *adma, t_adm *admb);

// Libft

long	ft_atoi(const char *s);
char	*ft_strdup(const char *s1);
char	**ft_split(const char *s, char c);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(const char *str);
char	*ft_strjoin(int size, char **strs, char *sep);

#endif
