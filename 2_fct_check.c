/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_fct_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:49:56 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/25 09:56:21 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_init_sort(int *s_a, t_var var)
{
	int	i;

	i = 0;
	while (i < var.max_len - 1)
	{
		if (s_a[i] > s_a[i + 1])
			return (1);
		else
			i++;
	}
	return (0);
}

int	ft_check_reverse_sort(int *s_a, t_var *var)
{
	int	i;

	i = var->max_len - 1;
	while (i > 0)
	{
		if (s_a[i] > s_a[i - 1])
			return (0);
		else
			i--;
	}
	return (1);
}

int	ft_check_dupl(t_arg *arg)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arg->av && i < arg->ac - 1)
	{
		j = i + 1;
		while (arg->av && j < arg->ac - 1)
		{
			if (!(ft_strcmp(arg->av[i], arg->av[j])))
			{
				write(2, "Error\n", 6);
				ft_free_split(arg->av);
				return (0);
			}
			else
				j++;
		}
		i++;
	}
	return (1);
}

static int	ft_minmax_free(t_arg *arg, long *tmp)
{
	if (arg->av[0][0] != '.' && arg->av[0][0] != '/')
		ft_free_split(arg->av);
	if (tmp)
		free(tmp);
	return (0);
}

int	ft_check_minmax(t_arg *arg, int k)
{
	long		*tmp;
	int			j;

	tmp = malloc(sizeof(long) * (arg->ac));
	if (tmp == NULL)
		return (ft_minmax_free(arg, tmp));
	j = 0;
	while (k < arg->ac - 1)
	{
		tmp[j] = ft_atoi(arg->av[k]);
		if (tmp[j] > 2147483647 || tmp[j] < -2147483648
			|| ft_strlen(arg->av[k]) > 12)
		{
			write(2, "Error\n", 6);
			return (ft_minmax_free(arg, tmp));
		}
		j++;
		k++;
	}
	free(tmp);
	return (1);
}
