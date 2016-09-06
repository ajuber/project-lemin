/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_chemin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 05:14:35 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/07 00:09:29 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	del_chemin(t_e *e)
{
	t_l_chemin *tmp;
	t_l_chemin *tmp_previous;

	tmp = e->chemin;
	tmp_previous = e->chemin;
	if (tmp->next)
		tmp = tmp->next;
	while (tmp->next)
	{
		tmp = tmp->next;
		tmp_previous = tmp_previous->next;
	}
	ft_free_list_lem1(&tmp->chemin);
	free(tmp);
	tmp = NULL;
	tmp_previous->next = NULL;
}
