/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_fourmi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 03:48:24 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/06 03:48:57 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_free_fourmi(t_fourmi **begin_list)
{
	if (begin_list && begin_list[0])
		free(begin_list[0]);
	begin_list[0] = NULL;
}
