/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 18:17:56 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/02 03:56:36 by ajubert          ###   ########.fr       */
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
	if (!no_start_no_end(&e))
		return (0);
	if (!recup_liaison(&e))
		return (0);
	ft_print_salle(&e);
	ft_print_liaison(&e);
	if (!convert_liaison(&e))
		return (0);
	ft_print_convert_liaison(&e);
	if (!(e.chemin = push_back_chemin(e.chemin)))
		return (0);
	if (!(e.chemin->chemin = push_back_lem1(e.chemin->chemin, e.start1)))
		return (0);
	create_chemin(&e);
	ft_print_chemin(&e);
	return (0);
}
