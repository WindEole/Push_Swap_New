/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_stack_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:48:58 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/21 23:07:44 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

static int	ft_appel_gnl(t_var *var, t_adm *adm)
{
	char	*line;
	int		ret;

	ret = get_next_line(1, &line);
	free(&line);
	while (ret == 1)
	{
		ret = get_next_line(1, &line);
		free(&line);
	}
}

static int	ft_stack_to_list(int *s_a, int *s_b, t_var *var)
{
	int		i;
	t_dll	*dll;
	t_adm	*adm[2];
	t_dll	*now[3];

	adm[0] = NULL;
	adm[1] = NULL;
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
	ft_appel_gnl(NULL, *adm);
	ft_free_stack(adm, NULL, NULL, NULL);
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
	if (var->len_a <= 5)
		ft_appel_gnl(var, NULL);
	else
		ft_stack_to_list(s_a, s_b, var);
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
