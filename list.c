/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 15:32:08 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/06 03:15:57 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_liste		*new_list(char *str, char *str1, int s)
{
	t_liste *new;

	if (!(new = (t_liste *)malloc(sizeof(t_liste))))
		return (NULL);
	new->next = NULL;
	if (!(new->str = (char *)malloc(sizeof(char) * (s + 1))))
		return (NULL);
	ft_strncpy(new->str, str, s);
	new->str[s] = '\0';
	if (!(new->str1 = ft_strdup(str1)))
		return (NULL);
	return (new);
}

t_liste		*push_back_lem(t_liste *begin_list, char *str, char *str1, int s)
{
	t_liste *new;
	t_liste *tmp;

	if (!(new = new_list(str, str1, s)))
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

int					count_list_lem(t_liste *begin_list)
{
	int			i;
	t_liste		*tmp;

	tmp = begin_list;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}


void				ft_free_list_lem(t_liste **begin_list)
{
	t_liste *tmp;
	t_liste *tmp1;

	tmp1 = begin_list[0];
	if (tmp1 && tmp1->next)
	{
		tmp1 = tmp1->next;
		while (tmp1 != NULL)
		{
			tmp = tmp1;
			tmp1 = tmp1->next;
			free(tmp->str);
			free(tmp->str1);
			ft_memdel((void **)&tmp);
		}
	}
	if (begin_list[0])
	{
		free(begin_list[0]->str);
		free(begin_list[0]->str1);
		free(begin_list[0]);
	}
	tmp1 = NULL;
	begin_list[0] = NULL;
}
