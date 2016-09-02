/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste_chemin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 00:31:36 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/02 00:35:12 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_l_chemin		*new_list()
{
	t_l_chemin *new;

	if (!(new = (t_l_chemin *)malloc(sizeof(t_l_chemin))))
		return (NULL);
	new->next = NULL;
	new->chemin = NULL;
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

void				ft_free_list_lem1(t_liste1 **begin_list)
{
	t_liste1 *tmp;
	t_liste1 *tmp1;

	tmp1 = begin_list[0];
	if (tmp1 && tmp1->next)
	{
		tmp1 = tmp1->next;
		while (tmp1 != NULL)
		{
			tmp = tmp1;
			tmp1 = tmp1->next;
			ft_memdel((void **)&tmp);
		}
	}
	if (begin_list[0])
		free(begin_list[0]);
	tmp1 = NULL;
	begin_list[0] = NULL;
}
