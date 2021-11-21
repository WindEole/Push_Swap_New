/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:01:50 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/19 21:15:00 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rot(t_adm *adm, char *s)
{
	if (!adm->head)
		return ;
	adm->head = adm->head->next;
	adm->tail = adm->head->prev;
	if (s)
		write(1, &s[0], 3);
}

void	ft_revrot(t_adm *adm, char *s)
{
	if (!adm->head)
		return ;
	adm->head = adm->head->prev;
	adm->tail = adm->head->prev;
	if (s)
		write(1, &s[0], 4);
}

void	ft_swap(t_adm *adm, char *s)
{
	int	y;

	if (!adm->head)
		return ;
	y = adm->head->arg;
	adm->head->arg = adm->head->next->arg;
	adm->head->next->arg = y;
	y = adm->head->i;
	adm->head->i = adm->head->next->i;
	adm->head->next->i = y;
	if (s)
		write(1, &s[0], 3);
}

static void	ft_push_suite(t_adm *lstto, t_dll *now)
{
	if (!lstto->head)
	{
		lstto->head = now;
		lstto->head->next = now;
		lstto->head->prev = now;
		lstto->tail = now;
	}
	else
	{
		now->next = lstto->head;
		now->prev = lstto->tail;
		lstto->head->prev = now;
		lstto->tail->next = now;
		lstto->head = now;
	}
}

void	ft_push(t_adm *lstfrom, t_adm *lstto, char *s)
{
	t_dll	*now;

	if (!lstfrom->head)
		return ;
	now = lstfrom->head;
	if (now->next = now)
	{
		lstfrom->head = NULL;
		lstfrom->tail = NULL;
	}
	else
	{
		lstfrom->head = now->next;
		lstfrom->head->prev = lstfrom->tail;
		lstfrom->tail->next = lstfrom->head;
	}
	ft_push_suite(lstto, now);
	if (s)
		write(1, &s[0], 3);
}
