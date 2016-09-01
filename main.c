/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 18:17:56 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/01 05:20:19 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(void)
{
	t_e e;

	ft_bzero(&e, sizeof(t_e));
	ft_printf("avant recup_nb_ant\n");
	if (!recup_nb_ant(&e))
		return (0);
	ft_printf("nb_fourmi : %d\n", e.nb_ant);
	ft_printf("avant recup_salle\n");
	if (!recup_salle(&e))
		return (0);
	ft_printf("avant recup_liaison\n");
	if (!recup_liaison(&e))
		return (0);
	ft_print_salle(&e);
	ft_print_liaison(&e);
	convert_liaison(&e);
	return (0);
}
