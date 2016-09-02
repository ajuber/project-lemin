/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_liaison.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 00:55:36 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/02 04:17:00 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_liaison(t_e *e, int i)
{
	t_l_chemin *tmp;
	t_liste1 *tmp1;
	t_liste1 *fin;

	tmp = e->chemin;
	while (tmp->next)
		tmp = tmp->next;
	tmp1 = tmp->chemin;
	fin = tmp1;
	while (fin->next)
		fin = fin->next;
	if (ft_strcmp(fin->str, e->end1) == 0)
		return (0);
	if (ft_strcmp(fin->str, e->liaison1[i][0]) && ft_strcmp(fin->str, e->liaison1[i][1]))
		return (0);
	if (ft_strcmp(fin->str, e->liaison1[i][0]) == 0)
		e->new_salle = e->liaison1[i][1];
	else
		e->new_salle = e->liaison1[i][0];
	while (tmp1)
	{
		if (ft_strcmp(tmp1->str, e->new_salle) == 0)
			return (0);
		tmp1 = tmp1->next;
	}
	return (1);
}
