/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_salle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 21:59:15 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/31 05:06:44 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		recup_salle(t_e *e)
{
	while (get_next_line(0, &e->line))
	{
		if (!is_infos())
		{
			if (is_liaison())
			{
				return (1);
			}
			if (!get_salle() || !get_coor())
				return (0);
			free_line(&e->line);
		}
	}
	return (0);
}
