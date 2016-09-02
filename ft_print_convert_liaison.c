/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_convert_liaison.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 23:22:49 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/01 23:25:53 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_print_convert_liaison(t_e *e)
{
	int i;
	int j;

	i = 0;
	ft_printf("convert_liaison\n");
	while (i < e->nb_liaison)
	{
		j = 0;
		while (j < 2)
		{
			ft_printf("%s-", e->liaison1[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
