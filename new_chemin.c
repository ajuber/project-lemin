/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_chemin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 03:35:32 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/04 19:27:39 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		new_chemin(t_e *e)
{
	t_l_chemin *tmp;
	t_l_chemin *tmp_previous;
	t_liste1 *tmp1;

	tmp = e->chemin;
	tmp_previous = e->chemin;
	if (!(e->chemin = push_back_chemin(e->chemin)))
		return (0);
	if (tmp->next)
		tmp = tmp->next;
	while (tmp->next)
	{
		tmp = tmp->next;
		tmp_previous = tmp_previous->next;
	}
	tmp_previous->nb_salle -= 1;
	tmp1 = tmp_previous->chemin;
	while (tmp1)
	{
		if (!(tmp->chemin = push_back_lem1(tmp->chemin, tmp1->str)))
			return (0);
		tmp1 = tmp1->next;
	}
	tmp->nb_salle = tmp_previous->nb_salle + 1;
	return (1);
}
