/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_invalid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 00:45:13 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/05 02:32:55 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	calcul_invalid(t_e *e)
{
	int diff;

	diff = e->chemin_order[e->ind_max].nb_salle - e->chemin_order[0].nb_salle;
//	ft_printf("diff : %d ind_max : %d nb_fourmi_parti : %d\n", diff, e->ind_max, e->nb_fourmi_parti);
	if (diff * e->ind_max > e->nb_fourmi_parti)
	{
		e->chemin_order[e->ind_max].valid = 0;
		e->chemins[e->chemin_order[e->ind_max].ind].valid = 0;
		e->ind_max--;
		e->nb_real_chemin--;
		calcul_invalid(e);
	}
}
