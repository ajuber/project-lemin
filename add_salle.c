/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_salle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 01:14:47 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/02 03:20:50 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		add_salle(t_e *e)
{
	t_l_chemin *tmp;
	t_liste1 *tmp1;

	tmp = e->chemin;
	while (tmp->next)
		tmp = tmp->next;
	tmp1 = tmp->chemin;
	if (!(tmp1 = push_back_lem1(tmp1, e->new_salle)))
		return (0);
	return (1);
}
