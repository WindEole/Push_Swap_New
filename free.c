/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 10:05:09 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/25 11:18:26 by iderighe         ###   ########.fr       */
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
	if (s_a && !adm)
		free(s_a);
	if (s_b && !adm)
		free(s_b);
	return (0);
}

/*
int	ft_check_sort(int *s_a, t_var var)
{
	int	i;
	int	j;

	i = 0;
	while (i < var.max_len - 1)
	{
		if (s_a[i] > s_a[i + 1])
		{
			printf(RED"KO ! You should get your code straight !"RESET
			YELLOW" nb total d'operation = %d"RESET"\n", var.add);
			j = 0;
			while (j < var.max_len)
		{
printf(RED"s_a[%d] = %d"RESET"\n", j, s_a[j]);
				j++;
			}
			return (1);
		}
		else
			i++;
	}
	printf(GREEN"OK ! Congratulations, your algorithme worked !"RESET
	YELLOW" nb total d'operation = %d"RESET"\n", var.add);
	i = 0;
	while (i < var.max_len)
	{
printf(GREEN"s_a[%d] = %d"RESET"\n", i, s_a[i]);
		i++;
	}
	return (0);
}*/
