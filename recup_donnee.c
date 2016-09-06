/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_donnee.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 22:48:11 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/05 22:59:25 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		recup_donnee(t_e *e)
{
	while (get_next_line(0, &e->line) > 0)
	{
		if (!(e->donne = push_back_lem1(e->donne, e->line)))
			return (0);
		free_line(&e->line);
	}
	return (1);
}
