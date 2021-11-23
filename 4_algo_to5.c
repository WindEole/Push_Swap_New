/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_algo_to5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:02:44 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/23 18:36:18 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_algo_3(int *s_a, t_var *var)
{
	if (s_a[0] < s_a[1])
	{
		ft_revrotate_a(s_a, var);
		if (s_a[0] > s_a[1])
			ft_swap_a(s_a, var);
		else
			return ;
	}
	if (s_a[0] > s_a[1])
	{
		if (s_a[0] < s_a[2])
			ft_swap_a(s_a, var);
		else
		{
			ft_rotate_a(s_a, var);
			if (s_a[0] > s_a[1])
				ft_swap_a(s_a, var);
		}
		return ;
	}
	return ;
}

void	ft_algo_2_3(int *s_a, t_var *var)
{
	if (var->len_a == 2)
	{
		if (s_a[0] > s_a[1])
			ft_swap_a(s_a, var);
		else
			return ;
	}
	else
		ft_algo_3(s_a, var);
	return ;
}

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

void	ft_algo_4_5(int *s_a, int *s_b, t_var *var)
{
	int	i;
	int	pos_min;
	int	pos_max;

	i = 0;
	ft_define_min_max(s_a, var);
//printf(RED"var->len_a = [%d], var->min = [%d], var->max[%d]"RESET"\n", var->len_a, var->min, var->max);
	
	while (i < var->len_a)
	{
		if (s_a[i] == var->min)
			pos_min = i;
		if (s_a[i] == var->max)
			pos_max = i;
		i++;
	}
	if (pos_min == var->len_a - 1 || pos_max == var->len_a - 1)
	{
		ft_revrotate_a(s_a, var);
		ft_push_b(s_a, s_b, var);
	}



	while (i <= var->len_a)
	{
//printf(GREEN"var->len_a = [%d],\n"RED"s_a[0] = [%d], i = %d"RESET"\n", var->len_a, s_a[0], i);
		if (s_a[0] == var->min || s_a[0] == var->max)
			ft_push_b(s_a, s_b, var);
		else
		{
			ft_rotate_a(s_a, var);
//printf(RED"s_a[0] = [%d], i = %d"RESET"\n", s_a[0], i);
}
		i++;
	}
	if (s_b[0] > s_b[1])
		ft_swap_b(s_b, var);
	ft_algo_2_3(s_a, var);
	ft_push_a(s_a, s_b, var);
	ft_push_a(s_a, s_b, var);
	ft_rotate_a(s_a, var);
}

/*

	ft_push_b(s_a, s_b, var);
	if (var->len_a > 4)
		ft_push_b(s_a, s_b, var);
//	if (var->len_b > 1 && s_b[0] < s_b[1])
//		ft_swap_b(s_b, var);
	ft_algo_3(s_a, var);
	while (i > 0)
	{
		if (var->len_b && s_b[0] > s_a[var->len_a - 1] || s_b[0] < s_a[0])
		{
			ft_push_a(s_a, s_b, var);
			if (s_a[0] > s_a[var->len_a - 1])
				ft_rotate_a(s_a, var);
		}
//		if (s_b[0] < s_a[0])
//			ft_push_a(s_a, s_b, var);
//		if (var->len_b 
		i--;
	}

}*/


/*
static void	ft_algo_common_4_5(int *s_a, int *s_b, t_var *var)
{
	if (s_b[0] < s_a[0])
		ft_push_a(s_a, s_b, var);
	else if (s_b[0] > s_a[var->len_a - 1])
	{
		ft_push_a(s_a, s_b, var);
		ft_rotate_a(s_a, var);
	}
	else if (s_b[0] > s_a[0] && s_b[0] < s_a[1])
	{
		ft_rotate_a(s_a, var);
		ft_push_a(s_a, s_b, var);
		ft_revrotate_a(s_a, var);
	}
	return ;
}

static void	ft_algo_5(int *s_a, int *s_b, t_var *var)
{
	if (s_a[0] > s_a[1])
		ft_swap_a(s_a, var);
	ft_push_b(s_a, s_b, var);
	ft_algo_4_5(s_a, s_b, var);
	if (s_b[0] < s_a[0] || s_b[0] > s_a[var->len_a - 1]
		|| (s_b[0] > s_a[0] && s_b[0] < s_a[1]))
		ft_algo_common_4_5(s_a, s_b, var);
	else if (s_b[0] > s_a[0] && s_b[0] > s_a[1] && s_b[0] > s_a[2])
	{
		ft_revrotate_a(s_a, var);
		ft_push_a(s_a, s_b, var);
		ft_rotate_a(s_a, var);
		ft_rotate_a(s_a, var);
	}
	else if (s_b[0] > s_a[0] && s_b[0] > s_a[1] && s_b[0] < s_a[2])
	{
		ft_revrotate_a(s_a, var);
		ft_revrotate_a(s_a, var);
		ft_push_a(s_a, s_b, var);
		ft_revrotate_a(s_a, var);
		ft_revrotate_a(s_a, var);
	}
	return ;
}

void	ft_algo_4_5(int *s_a, int *s_b, t_var *var)
{
	if (var->len_a == 4)
	{
		ft_push_b(s_a, s_b, var);
		if (!((s_a[0] < s_a[1]) && (s_a[1] < s_a[2])))
			ft_algo_3(s_a, var);
		if (s_b[0] < s_a[0] || s_b[0] > s_a[var->len_a - 1]
			|| (s_b[0] > s_a[0] && s_b[0] < s_a[1]))
			ft_algo_common_4_5(s_a, s_b, var);
		else if (s_b[0] > s_a[0] && s_b[0] > s_a[1])
		{
			ft_revrotate_a(s_a, var);
			ft_push_a(s_a, s_b, var);
			ft_rotate_a(s_a, var);
			ft_rotate_a(s_a, var);
		}
		return ;
	}
	else
		ft_algo_5(s_a, s_b, var);
	return ;
}
*/
