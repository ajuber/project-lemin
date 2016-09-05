/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_chemin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 19:28:11 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/04 20:30:52 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		convert_chemin(t_e *e)
{
	int i;
	t_liste1 *tmp;
	t_l_chemin *tmp1;
	int j;

	ft_printf("dans convert_chemin\n");
	i = 0;
	if (!(e->chemins = (t_tab_chemin *)malloc(sizeof(t_tab_chemin) * e->nb_chemin)))
		return (0);
	tmp1 = e->chemin;
	ft_printf("avant premier while\n");
	while (i < e->nb_chemin)
	{
		if (!(e->chemins[i].tab = (char **)malloc(sizeof(char *) * (tmp1->nb_salle + 2))))
			return (0);
		e->chemins[i].nb_salle = tmp1->nb_salle + 2;
		e->chemins[i].valid = 1;
		tmp1 = tmp1->next;
		i++;
	}
	i = 0;
	ft_printf("avant 2e while\n");
	tmp1 = e->chemin;
	ft_printf("avant 2e while\n");
	while (i < e->nb_chemin)
	{
		j = 0;
		tmp = tmp1->chemin;
		while (tmp)
		{
			if (!(e->chemins[i].tab[j] = ft_strdup(tmp->str)))
				return (0);
			tmp = tmp->next;
			j++;
		}
		tmp1 = tmp1->next;
		i++;
	}
	return (1);
}
