/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 23:00:09 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/01 23:30:34 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		add_infos(t_e *e)
{
	t_liste *tmp;

	tmp = e->salle;
	while (tmp->next)
		tmp = tmp->next;
	if (e->start == 1)
	{
		if (!(e->start1 = ft_strdup(tmp->str)))
			return (0);
		e->start = 2;
	}
	if (e->end == 1)
	{
		if (!(e->end1 = ft_strdup(tmp->str)))
			return (0);
		e->end = 2;
	}
	return (1);
}
