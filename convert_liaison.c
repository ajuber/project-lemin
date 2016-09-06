/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_liaison.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 05:20:42 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/07 00:20:38 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		convert_liaison(t_e *e)
{
	int			i;
	t_liste		*tmp;

	i = 0;
	e->nb_liaison = count_list_lem(e->liaison);
	if (!(e->liaison1 = (char ***)malloc(sizeof(char **) * e->nb_liaison)))
		return (0);
	while (i < e->nb_liaison)
	{
		if (!(e->liaison1[i] = (char **)malloc(sizeof(char *) * 2)))
			return (0);
		i++;
	}
	tmp = e->liaison;
	i = 0;
	while (i < e->nb_liaison)
	{
		if (!(e->liaison1[i][0] = ft_strdup(tmp->str)))
			return (0);
		if (!(e->liaison1[i][1] = ft_strdup(tmp->str1)))
			return (0);
		i++;
		tmp = tmp->next;
	}
	return (1);
}
