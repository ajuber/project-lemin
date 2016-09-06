/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chemin_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 03:23:05 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/07 00:28:23 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		chemin_valid(t_e *e)
{
	t_l_chemin	*tmp;
	t_liste1	*tmp1;

	tmp = e->chemin;
	while (tmp->next)
		tmp = tmp->next;
	tmp1 = tmp->chemin;
	while (tmp1->next)
		tmp1 = tmp1->next;
	if (ft_strcmp(tmp1->str, e->end1))
		return (0);
	e->nb_chemin++;
	return (1);
}
