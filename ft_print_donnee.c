/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_donnee.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 02:15:42 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/06 23:49:14 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		ft_print_donnee1(t_e *e)
{
	t_liste1 *tmp;

	tmp = e->donne;
	while (tmp != e->last_acq)
	{
		ft_printf("%s\n", tmp->str);
		tmp = tmp->next;
	}
}

static void		ft_print_donnee2(t_e *e)
{
	t_liste1 *tmp;

	tmp = e->donne;
	while (tmp)
	{
		ft_printf("%s\n", tmp->str);
		tmp = tmp->next;
	}
}

void			ft_print_donnee(t_e *e)
{
	if (e->donnee_error)
		ft_print_donnee1(e);
	else
		ft_print_donnee2(e);
	ft_printf("\n");
}
