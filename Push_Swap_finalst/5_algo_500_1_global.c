/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_algo_500_1_global.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 16:58:59 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/19 21:12:05 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*static void	ft_define_min_max(int *s_a, t_var *var)
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
}*/

int	ft_algo_big_numbers(int *s_a, int *s_b, t_var *var)
{
	int	i;
	int	j;
	int	reverse_sort;

	reverse_sort = ft_check_reverse_sort(s_a, var);
	if (reverse_sort == 1)
	{
		i = var->len_a;
		while (i-- > 1)
		{
			ft_revrotate_a(s_a, var);
			ft_push_b(s_a, s_b, var);
		}
		j = var->len_b;
		while (j-- > 0)
			ft_push_a(s_a, s_b, var);
	}
	if (reverse_sort == 0)
	{
		ft_stack_to_list(s_a, s_b, var);
//		ft_define_min_max(s_a, var);
//		ft_create_index(s_a, s_b, var);
	}
	return (1);
}

/*static void	ft_finish_sort(int *s_a, int *s_b, t_var *var, int pos_max)
{
	int	j;

	while (!(s_b[0] == var->max))
	{
		if (pos_max <= var->len_b / 2)
			ft_rotate_b(s_b, var);
		else if (pos_max > var->len_b / 2)
			ft_revrotate_b(s_b, var);
	}
	j = 0;
	while (j < var->max_len)
	{
		if (s_b[0] < s_b[1])
			ft_swap_b(s_b, var);
		ft_push_a(s_a, s_b, var);
		j++;
	}
}

void	ft_loop_browse(int *s_a, int *s_b, int *index_sa, t_var *var)
{
	int	i;
	int	pos_max;

	i = 0;
	free(index_sa);
	while (var->len_b != 0 && var->len_b < var->max_len)
	{
		ft_create_new_index(s_a, var);
		ft_move_to_top_a(s_a, s_b, var);
		i++;
	}
	i = 0;
	pos_max = 0;
	while (i < var->len_b)
	{
		if (s_b[i] == var->max)
			pos_max = i;
		i++;
	}
	ft_finish_sort(s_a, s_b, var, pos_max);
}*/

t_adm	*ft_list_init_b(t_adm *adm)
{
	adm = malloc(sizeof(*adm));
	if (adm == NULL)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	adm->head = NULL;
	adm->tail = NULL;
	return (adm);
}

t_adm	*ft_list_init_a(t_adm *adm, t_dll *dll, int first)
{
	adm = malloc(sizeof(*adm));
	dll = malloc(sizeof(*dll));
	if (adm == NULL || dll == NULL)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	adm->head = dll;
	adm->tail = dll;
	dll->arg = first;
	dll->i = 0;
	dll->next = adm->head;
	dll->prev = adm->tail;
	return (adm);
}

int	ft_list_inser(t_adm *adm, int n)
{
	t_dll	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	new->arg = n;
	new->i = 0;
	new->next = adm->head;
	new->prev = adm->tail;
	adm->head->prev = new;
	adm->tail->next = new;
	adm->tail = new;
	return (1);
}

int	ft_lstlen(t_adm *adm)
{
	t_dll	*now;
	int		i;

	now = adm->head;
	if (!adm->head)
		return (0);
	i = 1;
	while (now != adm->tail)
	{
		i++;
		now = now->next;
	}
	return (i);
}

void	ft_create_index(t_adm *adm)
{
	t_dll	*now[2];
	int		x[2];

	now[1] = adm->head;
	x[0] = 0;
	while (x[0]++ < ft_lstlen(adm))
	{
		now[0] = adm->head;
		x[1] = 0;
		while (x[1]++ < ft_lstlen(adm))
		{
			if (now[1]->arg > now[0]->arg)
				now[1]->i++;
			now[0] = now[0]->next;
		}
		now[1] = now[1]->next;
	}
}

int	ft_stack_to_list(int *s_a, int *s_b, t_var *var)
{
	int	i;
	t_dll *dll;
	t_adm *adma;
	t_adm *admb;
	t_dll *now[3];

	adma = ft_list_init_a(adma, dll, s_a[0]);
	admb = ft_list_init_b(admb);
	if (adma == NULL || admb == NULL)
		return (ft_free_stack(adma, admb, NULL, s_a, s_b));
	i = 1;
	while (i < var->len_a)
	{
		if(!(ft_list_inser(adma, s_a[i])))
			return (ft_free_stack(adma, admb, NULL, s_a, s_b));
		i++;
	}
	ft_create_index(adma);
	ft_push(adma, admb, "pb\n");
	ft_algorithme(adma, admb, now, 0);
	return (1);
}
