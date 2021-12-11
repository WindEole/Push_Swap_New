/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_stack_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:48:58 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/25 14:03:32 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_var	ft_init_var(int max_len)
{
	t_var	var;

	var.len_a = max_len;
	var.len_b = 0;
	var.add = 0;
	var.min = 0;
	var.max = 0;
	var.pos_first = -1;
	var.pos_second = -1;
	var.max_len = max_len;
	return (var);
}

static int	ft_stack_to_list(int *s_a, int *s_b, t_var *var)
{
	int		i;
	t_dll	*dll;
	t_adm	*adm[2];
	t_dll	*now[3];

	dll = NULL;
	adm[0] = ft_list_init_a(adm[0], dll, s_a[0]);
	adm[1] = ft_list_init_b(adm[1]);
	if (adm[0] == NULL || adm[1] == NULL)
		return (ft_free_stack(adm, NULL, s_a, s_b));
	i = 1;
	while (i < var->len_a)
	{
		if (!(ft_list_inser(adm[0], s_a[i])))
			return (ft_free_stack(adm, NULL, s_a, s_b));
		i++;
	}
	ft_create_index(adm[0]);
	ft_push(adm[0], adm[1], "pb\n");
	ft_tri(adm[0], adm[1], now, 0);
	ft_free_stack(adm, NULL, NULL, NULL);
	return (1);
}

static int	ft_algo_big_numbers(int *s_a, int *s_b, t_var *var)
{
	int	i;
	int	j;
	int	reverse_sort;

	reverse_sort = ft_check_reverse_sort(s_a, var);
	if (reverse_sort == 1)
	{
		i = var->len_a;
		while (i-- > 1)
		{
			ft_revrotate_a(s_a, var);
			ft_push_b(s_a, s_b, var);
		}
		j = var->len_b;
		while (j-- > 0)
			ft_push_a(s_a, s_b, var);
	}
	if (reverse_sort == 0)
		ft_stack_to_list(s_a, s_b, var);
	return (1);
}

static int	ft_parsing(int *s_a, int *s_b, t_arg *arg, t_var *var)
{
	if (arg->av[0][0] != '.' && arg->av[0][0] != '/')
		ft_free_split(arg->av);
	if (!(ft_check_init_sort(s_a, *var)))
	{
		free(s_a);
		free(s_b);
		return (1);
	}
	if (var->len_a <= 3)
		ft_algo_2_3(s_a, var);
	else if (var->len_a > 3 && var->len_a <= 5)
		ft_algo_4_5(s_a, s_b, var);
	else
		ft_algo_big_numbers(s_a, s_b, var);
	ft_free_stack(NULL, NULL, s_a, s_b);
	return (1);
}

int	ft_create_stack(t_arg *arg, t_var *var)
{
	int	*s_a;
	int	*s_b;
	int	t[2];

	s_a = malloc(sizeof(int) * var->max_len);
	s_b = malloc (sizeof(int) * var->max_len);
	if (s_a == NULL || s_b == NULL)
		return (ft_free_stack(NULL, arg, s_a, s_b));
	t[1] = 0;
	t[0] = 0;
	while (t[0] < arg->ac - 1)
	{
		s_a[t[1]] = ft_atoi(arg->av[t[0]]);
		s_b[t[1]] = 0;
		t[1]++;
		t[0]++;
	}
	if (!(ft_parsing(s_a, s_b, arg, var)))
		return (0);
	return (1);
}
