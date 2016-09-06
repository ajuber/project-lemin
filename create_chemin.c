/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chemin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 00:09:41 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/07 00:22:42 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		create_chemin(t_e *e)
{
	int i;

	i = 0;
	while (i < e->nb_liaison)
	{
		if (check_liaison(e, i) != 0)
		{
			if (!(add_salle(e)))
				ft_print_error(e);
			if (chemin_valid(e))
				new_chemin(e);
			if (create_chemin(e) != 0)
				return (1);
			del_last_salle(e);
		}
		i++;
	}
	return (0);
}
