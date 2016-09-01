/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_liaison.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 03:41:05 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/01 03:57:17 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_print_liaison(t_e *e)
{
	t_liste *tmp;

	ft_printf("liaison\n");
	tmp = e->liaison;
	while (tmp)
	{
		ft_printf("%s-%s\n", tmp->str, tmp->str1);
		tmp = tmp->next;
	}
}
