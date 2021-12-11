/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_algo_to5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:02:44 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/25 09:58:11 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_define_min_max(int *s_a, t_var *var)
{
	int	i;

	i = 0;
	var->min = s_a[0];
	while (i < var->max_len)
	{
		if (s_a[i] < var->min)
			var->min = s_a[i];
		i++;
	}
	i = 0;
	var->max = s_a[0];
	while (i < var->max_len)
	{
		if (s_a[i] > var->max)
			var->max = s_a[i];
		i++;
	}
}

static int	ft_check_sort(int *s_a, int i, t_var *var)
{
	while (i < var->len_a - 1)
	{
		if (s_a[i] > s_a[i + 1])
			return (1);
		else
			i++;
	}
	return (0);
}

static void	ft_algo_4(int *s_a, int *s_b, t_var *var)
{
	ft_push_b(s_a, s_b, var);
	if (ft_check_sort(s_a, 0, var))
		ft_algo_2_3(s_a, var);
	if (s_b[0] < s_a[0] || s_b[0] > s_a[var->len_a - 1])
	{
		ft_push_a(s_a, s_b, var);
		if (s_a[0] > s_a[1])
			ft_rotate_a(s_a, var);
	}
	else if (s_b[0] > s_a[0] && s_b[0] < s_a[1])
	{
		ft_rotate_a(s_a, var);
		ft_push_a(s_a, s_b, var);
		ft_revrotate_a(s_a, var);
	}
	else if (s_b[0] > s_a[1] && s_b[0] < s_a[2])
	{
		ft_revrotate_a(s_a, var);
		ft_push_a(s_a, s_b, var);
		ft_rotate_a(s_a, var);
		ft_rotate_a(s_a, var);
	}
	return ;
}

static void	ft_push_to_b(int *s_a, int *s_b, t_var *var)
{
	if (s_a[0] == var->min || s_a[0] == var->max)
		ft_push_b(s_a, s_b, var);
	else if (s_a[1] == var->min || s_a[1] == var->max)
	{
		ft_rotate_a(s_a, var);
		ft_push_b(s_a, s_b, var);
	}
	else if (s_a[var->len_a - 1] == var->min || s_a[var->len_a - 1] == var->max)
	{
		ft_revrotate_a(s_a, var);
		ft_push_b(s_a, s_b, var);
	}
	else if (s_a[2] == var->min || s_a[2] == var->max)
	{
		ft_rotate_a(s_a, var);
		ft_rotate_a(s_a, var);
		ft_push_b(s_a, s_b, var);
	}
}

void	ft_algo_4_5(int *s_a, int *s_b, t_var *var)
{
	if (var->len_a == 4)
		ft_algo_4(s_a, s_b, var);
	ft_define_min_max(s_a, var);
	ft_push_to_b(s_a, s_b, var);
	ft_push_to_b(s_a, s_b, var);
	if (ft_check_sort(s_a, 0, var))
		ft_algo_2_3(s_a, var);
	ft_push_a(s_a, s_b, var);
	if (s_a[0] > s_a[var->len_a - 1])
		ft_rotate_a(s_a, var);
	ft_push_a(s_a, s_b, var);
	if (s_a[0] > s_a[var->len_a - 1])
		ft_rotate_a(s_a, var);
}
