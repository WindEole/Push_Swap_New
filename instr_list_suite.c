/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_list_suite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:24:49 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/23 12:25:33 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr(t_adm *adma, t_adm *admb)
{
	ft_rot(adma, NULL);
	ft_rot(admb, NULL);
	write (1, "rr\n", 3);
}

void	ft_rrr(t_adm *adma, t_adm *admb)
{
	ft_revrot(adma, NULL);
	ft_revrot(admb, NULL);
	write (1, "rrr\n", 4);
}

void	ft_ss(t_adm *adma, t_adm *admb)
{
	ft_swap(adma, NULL);
	ft_swap(admb, NULL);
	write (1, "ss\n", 3);
}
