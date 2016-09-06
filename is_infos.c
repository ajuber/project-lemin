/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_infos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 22:10:25 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/06 23:43:57 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		under(t_e *e, int i)
{
	if (!e->last_acq)
		ft_print_error(e);
	if (e->last_acq->str[0] == 'L')
		ft_print_error(e);
	if (ft_strcmp("##start", e->last_acq->str) == 0 && i == 2)
		ft_print_error(e);
	if (ft_strcmp("##start", e->last_acq->str) == 0 && e->start != 0)
		ft_print_error(e);
	if (ft_strcmp("##start", e->last_acq->str) == 0)
		e->start = 1;
	if (ft_strcmp("##end", e->last_acq->str) == 0 && i == 1)
		ft_print_error(e);
	if (ft_strcmp("##end", e->last_acq->str) == 0 && e->end != 0)
		ft_print_error(e);
	if (ft_strcmp("##end", e->last_acq->str) == 0)
		e->end = 1;
}

int				is_infos(t_e *e, int i)
{
	under(e, i);
	if (e->last_acq && e->last_acq->str[0] == '#')
	{
		e->last_acq = e->last_acq->next;
		if (e->end == 1)
			is_infos(e, 2);
		if (e->start == 1)
			is_infos(e, 1);
	}
	if (!e->last_acq)
		ft_print_error(e);
	return (1);
}
