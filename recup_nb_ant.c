/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_nb_ant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 22:45:25 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/01 03:58:57 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		recup_nb_ant(t_e *e)
{
	int i;

	i = 0;
	while (get_next_line(0, &e->line) > 0 && e->line[0] == '#')
		free_line(&e->line);
	while (e->line[i])
	{
		if (!ft_isdigit(e->line[i]))
			return (0);
		i++;
	}
	e->nb_ant = ft_atoi(e->line);
	free_line(&e->line);
	return (1);
}
