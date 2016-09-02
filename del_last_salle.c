/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_last_salle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 03:48:33 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/02 03:54:31 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	del_last_salle(t_e *e)
{
	t_l_chemin *tmp;
	t_liste1 *tmp1;
	t_liste1 *tmp1_previous;

	tmp = e->chemin;
	while (tmp->next)
		tmp = tmp->next;
	tmp1 = tmp->chemin;
	tmp1_previous = tmp1;
	if (tmp1->next)
		tmp1 = tmp1->next;
	while (tmp1->next)
	{
		tmp1 = tmp1->next;
		tmp1_previous = tmp1_previous->next;
	}
	free(tmp1->str);
	free(tmp1);
	tmp1_previous->next = NULL;
}
