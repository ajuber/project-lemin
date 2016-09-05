/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fourmi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 21:28:23 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/04 21:59:52 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		init_fourmi(t_e *e)
{
	int i;

	i = 0;
	if (!(e->fourmi = (t_fourmi *)malloc(sizeof(t_fourmi) * e->nb_ant)))
		return (0);
	while (i < e->nb_ant)
	{
		e->fourmi[i].chemin = -1;
		e->fourmi[i].salle = 0;
		e->fourmi[i].valid = 0;
		i++;
	}
	return (1);
}
