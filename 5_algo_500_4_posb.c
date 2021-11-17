/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_algo_500_4_posb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:17:17 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/17 12:18:51 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_define_pos_in_b_min(int xa, int *s_b, t_var *var, int i)
{
	int	pos_in_b;

	pos_in_b = 0;
	while (i < var->len_b)
	{
		if (xa < s_b[i] && s_b[i] < s_b[i + 1])
		{
			if (xa == var->min)
			{
				if (i == var->len_b - 1)
					pos_in_b = 0;
				else
				{
					pos_in_b = i + 1;
					if (s_b[i + 1] > s_b[i])
						break ;
				}
			}
			else
				pos_in_b = i + 1;
		}
		i++;
	}
	return (pos_in_b);
}

static int	ft_define_pos_in_b_middle(int xa, int *s_b, t_var *var)
{
	int	i;
	int	j;
	int	pos_in_b;
	int	pos_in_b_value;

	i = 0;
	pos_in_b = 0;
	pos_in_b_value = var->min - 1;
	while (i < var->len_b)
	{
		j = 0;
		while (j < var->len_b)
		{
			if (s_b[j] >= s_b[i] && s_b[j] < xa && s_b[j] > pos_in_b_value
				&& s_b[i] < xa)
			{
				pos_in_b = j;
				pos_in_b_value = s_b[j];
			}
			j++;
		}
		i++;
	}
	return (pos_in_b);
}

int	ft_define_pos_in_b(int xa, int *s_b, t_var *var)
{
	int	i;
	int	pos_in_b;

	i = 0;
	pos_in_b = 0;
	while (i < var->len_b)
	{
		if (xa > s_b[i])
			break ;
		else
			i++;
	}
	if (i == var->len_b || xa == var->min)
		pos_in_b = ft_define_pos_in_b_min(xa, s_b, var, 0);
	else
		pos_in_b = ft_define_pos_in_b_middle(xa, s_b, var);
	return (pos_in_b);
}
