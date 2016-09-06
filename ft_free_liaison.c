/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_liaison.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 03:33:13 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/06 03:37:23 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_free_liaison(t_e *e, char ****begin)
{
	int i;
	int j;

	i = 0;
	if (begin && begin[0])
	{
		while (i < e->nb_liaison)
		{
			j = 0;
			while (j < 2)
			{
				free_line(&begin[0][i][j]);
				j++;
			}
			free(begin[0][i]);
			begin[0][i] = NULL;
			i++;
		}
	}
	if (begin[0])
		free(begin[0]);
	begin[0] = NULL;
}
