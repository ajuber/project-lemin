/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_liaison.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 03:00:12 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/06 02:04:54 by ajubert          ###   ########.fr       */
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
	if (e->last_acq->str[0] == '#')
		return (1);
	while (tmp && ft_strncmp(tmp->str, e->last_acq->str, ft_strlen(tmp->str)))
		tmp = tmp->next;
	if (tmp == NULL)
		return (0);
	tmp = e->salle;
	while (e->last_acq->str[i] && e->last_acq->str[i] != '-')
		i++;
	if (e->last_acq->str[i] == '\0')
		return (0);
	i++;
	if (e->last_acq->str[i] == '\0')
		return (0);
	ind = i;
	while (tmp && ft_strcmp(tmp->str, &e->last_acq->str[i]))
		tmp = tmp->next;
	if (tmp == NULL)
		return (0);
	if (!(e->liaison = push_back_lem(e->liaison, e->last_acq->str, &e->last_acq->str[ind], ind - 1)))
		return (0);
	return (1);
}

int		recup_liaison(t_e *e)
{
	if (!under(e))
		return (0);
	e->last_acq = e->last_acq->next;
	while (e->last_acq)
	{
		if (!under(e))
		{
			e->donnee_error = 1;
			return (1);
		}
		e->last_acq = e->last_acq->next;
	}
	return (1);
}
