/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_salle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 01:25:12 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/01 03:58:30 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		get_salle(t_e *e)
{
	int i;

	i = 0;
	if (e->line[i] == ' ')
		return (0);
	while (e->line[i] && e->line[i] != ' ')
		i++;
	if (e->line[i] == '\0')
		return (0);
	if (!(e->salle = push_back_lem(e->salle, e->line, "\0", i)))
		return (0);
	return (1);
}
