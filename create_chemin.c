/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chemin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 00:09:41 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/02 04:07:04 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		create_chemin(t_e *e)
{
	int i;
//	t_l_chemin *tmp;
//	t_liste1 *tmp1;

	i = 0;
/*	tmp = e->chemin;
	while (tmp->next)
		tmp = tmp->next;
	tmp1 = tmp->chemin;
	while (tmp1->next)
		tmp1 = tmp1->next;*/
//	if ((liste_triee(v->l_a, v->l_b)))
//	{
//		return (1);
//	}
	while (i < e->nb_liaison)
	{
		ft_printf("%d\n", i);
		if (check_liaison(e, i) != 0)
		{
			if (!(add_salle(e)))
			{
				exit (0);
			}
			if (chemin_valid(e))
				new_chemin(e);
			if (create_chemin(e) != 0)
				return (1);
			del_last_salle(e);
		}
		i++;
	}
	return (0);
}
