/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_algo_500_1_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 16:58:59 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/21 22:45:16 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

/*void	ft_create_index(t_adm *adm)
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
}*/
