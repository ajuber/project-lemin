/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_start_no_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 23:04:46 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/01 23:06:03 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		no_start_no_end(t_e *e)
{
	if (e->start != 2 || e->end != 2)
		return (0);
	return (1);
}
