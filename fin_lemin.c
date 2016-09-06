/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fin_lemin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 02:50:24 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/07 00:45:29 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	fin_lemin(t_e *e)
{
	free_line(&e->line);
	free_line(&e->start1);
	free_line(&e->end1);
	ft_free_list_lem(&e->salle);
	ft_free_list_lem(&e->liaison);
	ft_free_list_lem1(&e->donne);
	ft_free_list_chemin(&e->chemin);
	ft_free_tab_chemin(e, &e->chemins);
	ft_free_liaison(e, &e->liaison1);
	ft_free_fourmi(&e->fourmi);
	ft_free_chemin_order(&e->chemin_order);
}
