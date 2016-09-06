/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_infos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 22:10:25 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/06 00:04:22 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		is_infos(t_e *e, int i)
{
/*	if (e->line[0] == 'L')
		return (0);
	if (ft_strcmp("##start", e->line) == 0 && e->start != 0)
		return (0);
	if (ft_strcmp("##start", e->line) == 0)
		e->start = 1;
	if (ft_strcmp("##end", e->line) == 0 && e->end != 0)
		return (0);
	if (ft_strcmp("##end", e->line) == 0)
		e->end = 1;
	while (e->line[0] == '#')
	{
		free_line(&e->line);
		if (get_next_line(0, &e->line) <= 0)
			return (0);
	}*/
	if (!e->last_acq)
		return (0);
	if (e->last_acq->str[0] == 'L')
		return (0);
	if (ft_strcmp("##start", e->last_acq->str) == 0 && i == 2)
		return (0);
	if (ft_strcmp("##start", e->last_acq->str) == 0 && e->start != 0)
		return (0);
	if (ft_strcmp("##start", e->last_acq->str) == 0)
		e->start = 1;
	if (ft_strcmp("##end", e->last_acq->str) == 0 && i == 1)
		return (0);
	if (ft_strcmp("##end", e->last_acq->str) == 0 && e->end != 0)
		return (0);
	if (ft_strcmp("##end", e->last_acq->str) == 0)
		e->end = 1;
	if (e->last_acq && e->last_acq->str[0] == '#')
	{
		e->last_acq = e->last_acq->next;
		if (e->end == 1)
			is_infos(e, 2);
		if (e->start == 1)
			is_infos(e, 1);
	}
	if (!e->last_acq)
		return (0);
	return (1);
}
