/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_algo_500_2_tri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:36:32 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/20 16:48:42 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_move_to_top(t_adm *adm, int i)
{
	t_dll	*now;
	int		op;

	now = adm->head;
	op = 0;
	while (now->i != i && op++ != -1)
		now = now->next;
	now->rev = 0;
	if (op > (ft_lstlen(adm) / 2))
	{
		now = adm->head;
		op = 0;
		while (now->i != i && op++ != -1)
			now = now->prev;
		now->rev = 1;
	}
	return (op);
}

static void	ft_finish_sort(t_adm *adma, t_adm *admb)
{
	t_dll	*now;
	int		x;

	while (admb->head)
		ft_push(admb, adma, "pa\n");
	now = adma->head;
	x = ft_move_to_top(adma, 0);
	while (now->i != 0)
		now = now->next;
	while (x-- > 0)
	{
		if (now->rev)
			ft_revrot(adma, "rra\n");
		else
			ft_rot(adma, "ra\n");
	}
}

static void	ft_exec_opti(t_adm *adma, t_adm *admb, t_dll *opti)
{
	while (opti->opr-- > 0)
	{
		if (opti->rev)
			ft_rrr(adma, admb);
		else
			ft_rr(adma, admb);
	}
	while (opti->opa-- > 0)
	{
		if (opti->rev)
			ft_revrot(adma, "rra\n");
		else
			ft_rot(adma, "ra\n");
	}
	while (opti->opb-- > 0)
	{
		if (opti->revb)
			ft_revrot(admb, "rrb\n");
		else
			ft_rot(admb, "rb\n");
	}
	ft_push(adma, admb, "pb\n");
}

static t_dll	*ft_define_pos_in_b(t_dll *now, t_adm *admb)
{
	t_dll	*pos_b;
	int		x[2];

	pos_b = admb->head;
	x[0] = 0;
	x[1] = 0;
	if (admb->head == admb->tail)
		return (pos_b);
	while (x[0]++ < ft_lstlen(admb))
	{
		if (pos_b->i > x[1])
			x[1] = pos_b->i;
		if (pos_b->i < now->i && now->i < pos_b->prev->i)
			return (pos_b);
		pos_b = pos_b->next;
	}
	while (pos_b->i != x[1])
		pos_b = pos_b->next;
	return (pos_b);
}

void	ft_tri(t_adm *adma, t_adm *admb, t_dll **now, int x)
{
	while (adma->head)
	{
		x = 0;
		now[0] = adma->head;
		now[2] = adma->head;
		while (x++ < ft_lstlen(adma))
		{
			now[1] = ft_define_pos_in_b(now[0], admb);
			now[0]->opa = ft_move_to_top(adma, now[0]->i);
			now[0]->opb = ft_move_to_top(admb, now[1]->i);
			now[0]->revb = now[1]->rev;
			now[0]->opr = 0;
			if (now[0]->rev == now[0]->revb)
				while (now[0]->opa > 0 && now[0]->opb > 0
					&& now[0]->opa-- != -1 && now[0]->opb-- != -1)
					now[0]->opr++;
			now[0]->opt = (now[0]->opa) + (now[0]->opb) + (now[0]->opr);
			if (now[0]->opt < now[2]->opt)
				now[2] = now[0];
			now[0] = now[0]->next;
		}
		ft_exec_opti(adma, admb, now[2]);
	}
	ft_finish_sort(adma, admb);
}
