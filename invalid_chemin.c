/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_chemin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 20:27:42 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/06 23:41:23 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		under(t_e *e, int i, int j, int k)
{
	int l;

	l = 1;
	while (l < e->chemins[j].nb_salle - 1)
	{
		if (e->chemins[i].valid && e->chemins[j].valid &&
				ft_strcmp(e->chemins[i].tab[k], e->chemins[j].tab[l]) == 0)
		{
			e->nb_real_chemin--;
			if (e->chemins[j].nb_salle >= e->chemins[i].nb_salle)
				e->chemins[j].valid = 0;
			else
				e->chemins[i].valid = 0;
		}
		l++;
	}
}

void			invalid_chemin(t_e *e)
{
	int i;
	int j;
	int k;

	e->nb_real_chemin = e->nb_chemin;
	i = 0;
	while (i < e->nb_chemin)
	{
		j = i + 1;
		while (j < e->nb_chemin)
		{
			k = 1;
			while (k < e->chemins[i].nb_salle - 1)
			{
				under(e, i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}
