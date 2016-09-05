/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcours.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 21:24:47 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/05 02:32:39 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	parcours_graphe(t_e *e)
{
	int i;

	i = 0;
	while (i < e->nb_fourmi)
	{
		if (e->fourmi[i].chemin != -1)
			e->fourmi[i].salle += 1;
		i++;
	}
}

int		parcours(t_e *e)
{
	int i;
	int j;

	e->nb_fourmi = e->nb_ant;
	e->nb_fourmi_parti = e->nb_ant;
	if (!init_fourmi(e))
		return (0);
	while (e->nb_ant)
	{
		i = 0;
		calcul_invalid(e);
		j = 0;
		while (i < e->nb_chemin)
		{
			while (i < e->nb_chemin && e->chemins[i].valid == 0)
				i++;
			if (i < e->nb_chemin)
			{
			while (j < e->nb_fourmi && ((e->fourmi[j].chemin != -1 && e->fourmi[j].valid == 0) || (e->fourmi[j].chemin == -1 && e->fourmi[j].valid == 1)))
				j++;
			if (j < e->nb_fourmi)
			{
				e->fourmi[j].chemin = i;
				i++;
				e->nb_fourmi_parti--;
			}
			}
			if (j >= e->nb_fourmi)
				i++;
			//ft_printf("%d\n", i);
			j++;
		}
		parcours_graphe(e);
		ft_print_parcours(e);
		//ft_printf("%d\n", e->nb_ant);
	}
	return (1);
}