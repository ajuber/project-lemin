/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab_chemin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 03:17:46 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/07 00:06:41 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_free_tab_chemin(t_e *e, t_tab_chemin **begin_list)
{
	int i;
	int j;

	i = 0;
	if (begin_list && begin_list[0])
	{
		while (i < e->nb_chemin)
		{
			j = 0;
			while (j < begin_list[0][i].nb_salle)
			{
				free_line(&begin_list[0][i].tab[j]);
				j++;
			}
			free(begin_list[0][i].tab);
			begin_list[0][i].tab = NULL;
			i++;
		}
	}
	if (begin_list[0])
		free(begin_list[0]);
	begin_list[0] = NULL;
}
