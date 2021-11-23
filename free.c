/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 10:05:09 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/23 12:25:50 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}

void	ft_free_list(t_adm *adm)
{
	t_dll	*now;

	now = adm->head;
	while (now != adm->tail)
	{
		now = now->next;
		free(now->prev);
	}
	free(now);
	free(adm);
}

int	ft_free_stack(t_adm **adm, t_arg *arg, int *s_a, int *s_b)
{
	if (adm && adm[0])
		ft_free_list(adm[0]);
	if (adm && adm[1])
		ft_free_list(adm[1]);
	if (arg)
		if (arg->av[0][0] != '.' && arg->av[0][0] != '/')
			ft_free_split(arg->av);
	if (s_a)
		free(s_a);
	if (s_b)
		free(s_b);
	return (0);
}
