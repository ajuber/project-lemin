/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_nb_chemin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 05:30:02 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/06 05:35:26 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		calc_nb_chemin(t_e *e)
{
	int res;
	int i;

	res = 0;
	i = 0;
	while (i < e->nb_chemin)
	{
		if (e->chemins[i].valid != 0)
			res++;
		i++;
	}
	return (res);
}
