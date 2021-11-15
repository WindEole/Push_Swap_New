/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_fct_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:49:56 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/15 14:31:37 by iderighe         ###   ########.fr       */
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
	if (arg->av[0][0] == '.')
		i = 1;
	while (arg->av && i < arg->ac - 1)
	{
		j = i + 1;
		while (arg->av && j < arg->ac)
		{
			if (!(ft_strcmp(arg->av[i], arg->av[j])))
			{
				write(2, "Error\n", 6);
				return (0);
			}
			else
				j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_minmax(t_arg *arg, int k)
{
	long		*tmp;
	int			j;

	tmp = malloc(sizeof(long) * (arg->ac));
	if (tmp == NULL)
		return (0);
	j = 0;
	if (arg->av[0][0] == '.' || arg->av[0][0] == '/')
		k = 1;
	while (k < arg->ac)
	{
		tmp[j] = ft_atoi(arg->av[k]);
		if (tmp[j] > 2147483647 || tmp[j] < -2147483648
			|| ft_strlen(arg->av[k]) > 12)
		{
			write(2, "Error\n", 6);
			ft_free_split(arg->av);
			free(tmp);
			return (0);
		}
		j++;
		k++;
	}
	free(tmp);
	return (1);
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
