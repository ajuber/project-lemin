/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 02:23:14 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/06 23:46:04 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		get_coor(t_e *e)
{
	int i;

	i = 0;
	while (e->last_acq->str[i] && e->last_acq->str[i] != ' ')
		i++;
	if (e->last_acq->str[i] == '\0')
		return (0);
	i++;
	if (!ft_isdigit(e->last_acq->str[i]))
		return (0);
	while (e->last_acq->str[i] && ft_isdigit(e->last_acq->str[i]))
		i++;
	if (e->last_acq->str[i] == '\0' ||
			(!ft_isdigit(e->last_acq->str[i]) && e->last_acq->str[i] != ' '))
		return (0);
	i++;
	if (!ft_isdigit(e->last_acq->str[i]))
		return (0);
	while (e->last_acq->str[i] && ft_isdigit(e->last_acq->str[i]))
		i++;
	if (e->last_acq->str[i] != '\0')
		return (0);
	return (1);
}
