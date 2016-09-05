/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_convert_chemin.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 19:57:13 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/04 20:42:10 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_print_convert_chemin(t_e *e)
{
	int i;
	int j;

	i = 0;
	ft_printf("convert_chemin\n");
	while (i < e->nb_chemin)
	{
		j = 0;
		while (j < e->chemins[i].nb_salle)
		{
			if (e->chemins[i].valid)
				ft_printf("%s-", e->chemins[i].tab[j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
