/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste_chemin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 00:31:36 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/06 23:27:58 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_l_chemin		*new_list(void)
{
	t_l_chemin *new;

	if (!(new = (t_l_chemin *)malloc(sizeof(t_l_chemin))))
		return (NULL);
	new->next = NULL;
	new->chemin = NULL;
	new->nb_salle = 0;
	return (new);
}

t_l_chemin				*push_back_chemin(t_l_chemin *begin_list)
{
	t_l_chemin *new;
	t_l_chemin *tmp;

	if (!(new = new_list()))
		return (NULL);
	if (begin_list == NULL)
		begin_list = new;
	else
	{
		tmp = begin_list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (begin_list);
}

void					ft_free_list_chemin(t_l_chemin **begin_list)
{
	t_l_chemin *tmp;
	t_l_chemin *tmp1;

	tmp1 = begin_list[0];
	if (begin_list != NULL && tmp1 != NULL && tmp1->next != NULL)
	{
		tmp1 = tmp1->next;
		while (tmp1 != NULL)
		{
			tmp = tmp1;
			tmp1 = tmp1->next;
			ft_free_list_lem1(&tmp->chemin);
			ft_memdel((void **)&tmp);
		}
	}
	if (begin_list && begin_list[0])
	{
		ft_free_list_lem1(&begin_list[0]->chemin);
		free(begin_list[0]);
	}
	tmp1 = NULL;
	begin_list[0] = NULL;
}
