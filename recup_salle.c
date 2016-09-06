/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_salle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 21:59:15 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/06 01:13:32 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		recup_salle(t_e *e)
{
/*	while (get_next_line(0, &e->line) > 0)
	{
		ft_printf("avant is_infos\n");
		if (!is_infos(e))
			return (0);
		ft_printf("avant is_liaison\n");
		if (is_liaison(e))
		{
			return (1);
		}
		ft_printf("avant get_salle get_coor\n");
		if (!get_salle(e) || !get_coor(e))
			return (0);
		if (e->start == 1 || e->end == 1)
			if (!add_infos(e))
				return (0);
		free_line(&e->line);
	}*/
	e->last_acq = e->last_acq->next;
	while (e->last_acq)
	{
		if (!is_infos(e, 0))
			return (0);
		if (is_liaison(e))
			return (1);
		if (!get_salle(e) || !get_coor(e))
			return (0);
		if (e->start == 1 || e->end == 1)
			if (!add_infos(e))
				return (0);
		e->last_acq = e->last_acq->next;
	}
	return (0);
}
