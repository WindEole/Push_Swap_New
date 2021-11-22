/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_stack_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:48:58 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/22 15:12:31 by iderighe         ###   ########.fr       */
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

static int	ft_sort(t_adm *adma)
{
	t_dll	*now;

	now = adma->head;
	while (now != adma->tail)
	{
		if (now->next->arg < now->arg)
			return (0);
		else
			now = now->next;
	}
	return (1);
}

static int	ft_exec(t_adm *adma, t_adm *admb, char *line)
{
	if (ft_strcmp(line, "sa"))
		ft_swap(adma, NULL);
	if (ft_strcmp(line, "sb"))
		ft_swap(admb, NULL);
	if (ft_strcmp(line, "ss"))
		ft_ss(adma, admb, NULL);
	if (ft_strcmp(line, "ra"))
		ft_rot(adma, NULL);
	if (ft_strcmp(line, "rb"))
		ft_rot(admb, NULL);
	if (ft_strcmp(line, "rr"))
		ft_rr(adma, admb, NULL);
	if (ft_strcmp(line, "rra"))
		ft_revrot(adma, NULL);
	if (ft_strcmp(line, "rrb"))
		ft_revrot(admb, NULL);
	if (ft_strcmp(line, "rrr"))
		ft_rrr(adma, admb, NULL);
	if (ft_strcmp(line, "pa"))
		ft_push(admb, adma, NULL);
	if (ft_strcmp(line, "pb"))
		ft_push(adma, admb, NULL);
	return (1);
}

static int	ft_appel_gnl(t_adm *adma, t_adm *admb)
{
	char	*line;
	int		ret;

	ret = get_next_line(0, &line);
	if (ret == 0 && line[0] != '\0')
		return (0);
	free(line);
	while (ret == 1)
	{
		ret = get_next_line(0, &line);
		if (ft_exec(adma, admb, line) || (ret == 0 && line[0] != '\0'))
		{
			free(line);
			return (0);
		}
		free(line);
	}
	if (ft_lstlen(adma) != adma->base || ft_lstlen(admb) || !ft_sort(adma))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
//	ft_free_stack(&adma, NULL, NULL, NULL);
	return (1);
}

static int	ft_stack_to_list(int *s_a, int *s_b, t_var *var)
{
	int		i;
	t_dll	*dll;
	t_adm	*adm[2];

	adm[0] = NULL;
	adm[1] = NULL;
	dll = NULL;
	adm[0] = ft_list_init_a(adm[0], dll, s_a[0]);
	adm[1] = ft_list_init_b(adm[1]);
	adm[0]->base = ft_lstlen(adm[0]);
	if (adm[0] == NULL || adm[1] == NULL)
		return (ft_free_stack(adm, NULL, s_a, s_b));
	i = 1;
	while (i < var->len_a)
	{
		if (!(ft_list_inser(adm[0], s_a[i])))
			return (ft_free_stack(adm, NULL, s_a, s_b));
		i++;
	}
	if (!ft_appel_gnl(adm[0], adm[1]))
		return (0);
//	ft_free_stack(adm, NULL, s_a, s_b);
	return (1);
}

//static int	ft_parsing(int *s_a, int *s_b, t_arg *arg, t_var *var)
//{
//	if (arg->av[0][0] != '.' && arg->av[0][0] != '/')
//		ft_free_split(arg->av);
//	if (!(ft_check_init_sort(s_a, *var)))
//	{
//		free(s_a);
//		free(s_b);
//		return (1);
//	}
//	ft_stack_to_list(s_a, s_b, var);
//	ft_free_stack(NULL, NULL, s_a, s_b);
//	return (1);
//}

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
//	if (!(ft_parsing(s_a, s_b, arg, var)))
//		return (0);
	if (!ft_stack_to_list(s_a, s_b, var))
		return (0);
	ft_free_split(arg->av);
	return (1);
}
