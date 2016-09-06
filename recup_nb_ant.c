/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_nb_ant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 22:45:25 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/06 23:23:38 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		recup_nb_ant(t_e *e)
{
	int i;

	i = 0;
	e->last_acq = e->donne;
	if (e->last_acq == NULL)
		return (0);
	while (e->last_acq->str[i])
	{
		if (!ft_isdigit(e->last_acq->str[i]))
			return (0);
		i++;
	}
	e->nb_ant = ft_atoi(e->last_acq->str);
	return (1);
}
