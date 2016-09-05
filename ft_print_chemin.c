/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chemin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 03:56:56 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/04 17:59:13 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_print_chemin(t_e *e)
{
	t_l_chemin *tmp;
	t_liste1 *tmp1;

	tmp = e->chemin;
	ft_printf("print chemin\n");
	while (tmp)
	{
		ft_printf("%d\n", tmp->nb_salle + 2);
		tmp1 = tmp->chemin;
		while (tmp1)
		{
			ft_printf("%s-", tmp1->str);
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
		ft_printf("\n");
	}
}
