/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 05:16:28 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/02 05:20:23 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_liste1		*new_list(char *str)
{
	t_liste1 *new;

	if (!(new = (t_liste1 *)malloc(sizeof(t_liste1))))
		return (NULL);
	new->next = NULL;
	if (!(new->str = ft_strdup(str)))
		return (NULL);
	return (new);
}

t_liste1		*push_back_lem1(t_liste1 *begin_list, char *str)
{
	t_liste1 *new;
	t_liste1 *tmp;

	if (!(new = new_list(str)))
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
			free(tmp->str);
			ft_memdel((void **)&tmp);
		}
	}
	if (begin_list[0])
	{
		free(begin_list[0]->str);
		free(begin_list[0]);
	}
	tmp1 = NULL;
	begin_list[0] = NULL;
}
