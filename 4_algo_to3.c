/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_algo_to3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:51:02 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/25 09:51:39 by iderighe         ###   ########.fr       */
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
