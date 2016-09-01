/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_liaison.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 03:00:12 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/01 03:55:43 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	under(t_e *e)
{
	int		i;
	int		ind;
	t_liste	*tmp;

	i = 0;
	tmp = e->salle;
	while (tmp && ft_strncmp(tmp->str, e->line, ft_strlen(tmp->str)))
		tmp = tmp->next;
	if (tmp == NULL)
		return (0);
	tmp = e->salle;
	while (e->line[i] && e->line[i] != '-')
		i++;
	if (e->line[i] == '\0')
		return (0);
	i++;
	ind = i;
	while (tmp && ft_strcmp(tmp->str, &e->line[i]))
		tmp = tmp->next;
	if (tmp == NULL)
		return (0);
	if (!(e->liaison = push_back_lem(e->liaison, e->line, &e->line[ind], ind - 1)))
		return (0);
	free_line(&e->line);
	return (1);
}

int		recup_liaison(t_e *e)
{
	if (!under(e))
		return (0);
	while (get_next_line(0, &e->line) > 0)
		if (!under(e))
			return (0);
	return (1);
}
