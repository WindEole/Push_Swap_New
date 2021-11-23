/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:47:11 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/23 15:32:05 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

# define BUFFER_SIZE 128

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
	int	min;
	int	max;
	int	pos_first;
	int	pos_second;
	int	max_len;
}	t_var;

typedef struct s_dll
{
	int				arg;
	struct s_dll	*next;
	struct s_dll	*prev;
}	t_dll;

typedef struct s_adm
{
	int				base;
	struct s_dll	*head;
	struct s_dll	*tail;
}	t_adm;

// 2_fct_check.c

int		ft_check_init_sort(int *s_a, t_var var);
int		ft_check_reverse_sort(int *s_a, t_var *var);
int		ft_check_dupl(t_arg *arg);
int		ft_check_minmax(t_arg *arg, int k);

// 3_stack_parse.c

t_var	ft_init_var(int max_len);
int		ft_create_stack(t_arg *arg, t_var *var);

// 5_algo_500_1_list.c

t_adm	*ft_list_init_b(t_adm *adm);
t_adm	*ft_list_init_a(t_adm *adm, t_dll *dll, int first);
int		ft_list_inser(t_adm *adm, int n);
int		ft_lstlen(t_adm *adm);

// free.c

void	ft_free_split(char **str);
void	ft_free_list(t_adm *adm);
int		ft_free_stack(t_adm **adm, t_arg *arg, int *s_a, int *s_b);

// instr_list.c

int		ft_rot(t_adm *adm, char *s);
int		ft_revrot(t_adm *adm, char *s);
int		ft_swap(t_adm *adm, char *s);
int		ft_push(t_adm *lstfrom, t_adm *lstto, char *s);

// instr_list.c

int		ft_rr(t_adm *adma, t_adm *admb, char *s);
int		ft_rrr(t_adm *adma, t_adm *admb, char *s);
int		ft_ss(t_adm *adma, t_adm *admb, char *s);

// Libft

long	ft_atoi(const char *s);
char	*ft_strdup(const char *s1);
char	**ft_split(const char *s, char c);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(const char *str);
char	*ft_strjoin(int size, char **strs, char *sep);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strn(char *s);
int		get_next_line(int fd, char **line);

#endif
