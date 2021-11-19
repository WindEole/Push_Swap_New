/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_algo_500_2_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:36:32 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/19 21:16:48 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_define_pos_in_b(int xa, int *s_b, t_var *var)
{
	int	i;
	int	j;

	i = 0;
	j = var->min - 1;
	if (var->len_b == 1)
		return (i);
	while (i < var->len_b)
	{
		if (s_b[i] > j)
			j = s_b[i];
		if (i > 0)
		{
			if (xa > s_b[i] && xa < s_b[i - 1])
				return (i);
		}
		else if (xa > s_b[i] && xa < s_b[var->len_b - 1])
			return (i);
		i++;
	}
	return (i);
}

void	ft_algorithme(t_adm *adma, t_adm *admb, t_dll **now, int x)
{
	now[0] = adma->head;
	now[2] = adma->head;
	while (x++ < ft_lstlen(adma))
	{
		


	}
	
}
