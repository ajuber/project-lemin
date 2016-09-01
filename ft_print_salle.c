/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_salle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 03:38:38 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/01 03:57:42 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_print_salle(t_e *e)
{
	t_liste *tmp;

	ft_printf("salle\n");
	tmp = e->salle;
	while (tmp)
	{
		ft_printf("%s\n", tmp->str);
		tmp = tmp->next;
	}
}
