/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_parcours.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 22:28:51 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/06 23:47:09 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		test_fourmi_valid(t_e *e, int i)
{
	if (e->fourmi[i].salle + 1 == e->chemins[e->fourmi[i].chemin].nb_salle)
	{
		e->fourmi[i].chemin = -1;
		e->fourmi[i].valid = 1;
		e->nb_ant--;
	}
}

void			ft_print_parcours(t_e *e)
{
	int i;
	int test;

	test = 0;
	i = 0;
	while (i < e->nb_fourmi)
	{
		if (e->fourmi[i].chemin != -1 && e->fourmi[i].valid == 0)
		{
			if (test)
				ft_printf(" ");
			test = 1;
			ft_printf("L%d-%s", i + 1,
					e->chemins[e->fourmi[i].chemin].tab[e->fourmi[i].salle]);
			test_fourmi_valid(e, i);
		}
		i++;
	}
	ft_printf("\n");
}
