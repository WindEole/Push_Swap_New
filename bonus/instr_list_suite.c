/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_list_suite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:22:38 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/23 15:25:51 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_rr(t_adm *adma, t_adm *admb, char *s)
{
	ft_rot(adma, NULL);
	ft_rot(admb, NULL);
	if (s)
		write (1, &s[0], 3);
	return (0);
}

int	ft_rrr(t_adm *adma, t_adm *admb, char *s)
{
	ft_revrot(adma, NULL);
	ft_revrot(admb, NULL);
	if (s)
		write (1, &s[0], 4);
	return (0);
}

int	ft_ss(t_adm *adma, t_adm *admb, char *s)
{
	ft_swap(adma, NULL);
	ft_swap(admb, NULL);
	if (s)
		write (1, &s[0], 3);
	return (0);
}
