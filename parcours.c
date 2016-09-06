/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcours.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 21:24:47 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/06 23:22:19 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		parcours_graphe(t_e *e)
{
	int i;

	i = 0;
	while (i < e->nb_fourmi)
	{
		if (e->fourmi[i].chemin != -1)
		{
			e->fourmi[i].salle += 1;
			e->nb_deplacement++;
		}
		i++;
	}
}

static void		under(t_e *e, int *i, int *j)
{
	while (*i < e->nb_chemin && e->chemins[*i].valid != 1)
		*i += 1;
	if (*i < e->nb_chemin)
	{
		while (*j < e->nb_fourmi &&
				((e->fourmi[*j].chemin != -1 && e->fourmi[*j].valid == 0) ||
				(e->fourmi[*j].chemin == -1 && e->fourmi[*j].valid == 1)))
			*j += 1;
		if (*j < e->nb_fourmi)
		{
			e->fourmi[*j].chemin = *i;
			*i += 1;
			e->nb_fourmi_parti--;
		}
	}
	if (*j >= e->nb_fourmi)
		*i += 1;
	*j += 1;
}

int				parcours(t_e *e)
{
	int i;
	int j;

	e->nb_fourmi = e->nb_ant;
	e->nb_fourmi_parti = e->nb_ant;
	if (!init_fourmi(e))
		return (0);
	if (!e->b_e)
		ft_print_donnee(e);
	while (e->nb_ant)
	{
		i = 0;
		calcul_invalid(e);
		j = 0;
		while (i < e->nb_chemin)
			under(e, &i, &j);
		e->nb_tour++;
		parcours_graphe(e);
		ft_print_parcours(e);
	}
	return (1);
}
