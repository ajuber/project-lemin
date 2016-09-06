/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nb_salle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 05:50:03 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/06 06:10:09 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_nb_salle(t_e *e)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_printf("\n");
	while (i < e->nb_chemin)
	{
		if (e->chemins[i].valid != 0)
		{
			j++;
			ft_printf("chemin %d nombre de salle : %d\n", j, e->chemins[i].nb_salle);
		}
		i++;
	}
}
