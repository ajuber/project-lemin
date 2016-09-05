/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_order.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 00:56:44 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/05 01:20:30 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		create_order(t_e *e)
{
	int i;
	int j;

	if (!(e->chemin_order = (t_order *)malloc(sizeof(t_order) * e->nb_real_chemin)))
		return (0);
	i = 0;
	j = 0;
	while (i < e->nb_chemin)
	{
		if (e->chemins[i].valid)
		{
			e->chemin_order[j].ind = i;
			e->chemin_order[j].nb_salle = e->chemins[i].nb_salle;
			e->chemin_order[j].valid = 1;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < e->nb_real_chemin)
	{
		j = i + 1;
		while (j < e->nb_real_chemin)
		{
			if (e->chemin_order[j].nb_salle < e->chemin_order[i].nb_salle)
			{
				ft_swap_int(&e->chemin_order[i].nb_salle, &e->chemin_order[j].nb_salle);
				ft_swap_int(&e->chemin_order[i].ind, &e->chemin_order[j].ind);
			}
			j++;
		}
		i++;
	}
	e->ind_max = e->nb_real_chemin - 1;
	return (1);
}
