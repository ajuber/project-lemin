/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_liaison.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 03:00:12 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/06 23:21:11 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	under1(t_e *e, t_liste **tmp)
{
	tmp[0] = e->salle;
	if (e->last_acq->str[0] == '#')
		return (1);
	while (tmp[0] &&
			ft_strncmp(tmp[0]->str, e->last_acq->str, ft_strlen(tmp[0]->str)))
		tmp[0] = tmp[0]->next;
	if (tmp[0] == NULL)
		return (0);
	tmp[0] = e->salle;
	return (2);
}

static int	under(t_e *e)
{
	int		i;
	int		ind;
	t_liste	*tmp;

	i = 0;
	if (!(ind = under1(e, &tmp)))
		return (0);
	else if (ind == 1)
		return (1);
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
	if (!(e->liaison = push_back_lem(e->liaison,
					e->last_acq->str, &e->last_acq->str[ind], ind - 1)))
		return (0);
	return (1);
}

int			recup_liaison(t_e *e)
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
