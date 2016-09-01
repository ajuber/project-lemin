/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_infos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 22:10:25 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/01 04:13:09 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		is_infos(t_e *e)
{
	if (e->line[0] == 'L')
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
	}
	return (1);
}
