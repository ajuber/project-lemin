/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chemin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 03:56:56 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/06 06:08:49 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_print_chemin(t_e *e)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	ft_printf("\n\tChemin\n");
	while (i < e->nb_chemin)
	{
		if (e->chemins[i].valid != 0)
		{
			k++;
			ft_printf("Chemin %d :\n", k);
			j = 0;
			while (j < e->chemins[i].nb_salle)
			{
				ft_printf("%s", e->chemins[i].tab[j]);
				j++;
				if (j != e->chemins[i].nb_salle)
					ft_printf("-");
			}
			ft_printf("\n");
			if (e->b_x)
				ft_printf("Nombre de salle : %d\n", e->chemins[i].nb_salle);
			ft_printf("\n");
		}
		i++;
	}
}
