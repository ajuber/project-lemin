/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 02:23:14 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/01 03:20:12 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		get_coor(t_e *e)
{
	int i;

	i = 0;
	while (e->line[i] && e->line[i] != ' ')
		i++;
	if (e->line[i] == '\0')
		return (0);
	i++;
	if (!ft_isdigit(e->line[i]))
		return (0);
	while (e->line[i] && ft_isdigit(e->line[i]))
		i++;
	if (e->line[i] == '\0' || (!ft_isdigit(e->line[i]) && e->line[i] != ' '))
		return (0);
	i++;
	if (!ft_isdigit(e->line[i]))
		return (0);
	while (e->line[i] && ft_isdigit(e->line[i]))
		i++;
	if (e->line[i] != '\0')
		return (0);
	return (1);
}
