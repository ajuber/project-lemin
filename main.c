/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 18:17:56 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/06 03:42:02 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(void)
{
	t_e e;

	ft_bzero(&e, sizeof(t_e));
	if (!recup_donnee(&e))
	{
		fin_lemin(&e);
		ft_printf_fd(2, "ERROR\n");
		return (0);
	}
//	ft_printf("avant recup_nb_ant\n");
	if (!recup_nb_ant(&e))
	{
		fin_lemin(&e);
		ft_printf_fd(2, "ERROR\n");
		return (0);
	}
//	ft_printf("nb_fourmi : %d\n", e.nb_ant);
//	ft_printf("avant recup_salle\n");
	if (!recup_salle(&e))
	{
		fin_lemin(&e);
		ft_printf_fd(2, "ERROR\n");
		return (0);
	}
//	ft_printf("avant recup_liaison\n");
	if (!no_start_no_end(&e))
	{
		fin_lemin(&e);
		ft_printf_fd(2, "ERROR\n");
		return (0);
	}
	if (!recup_liaison(&e))
	{
		fin_lemin(&e);
		ft_printf_fd(2, "ERROR\n");
		return (0);
	}
//	ft_print_salle(&e);
//	ft_print_liaison(&e);
	if (!convert_liaison(&e))
	{
		fin_lemin(&e);
		ft_printf_fd(2, "ERROR\n");
		return (0);
	}
//	ft_print_convert_liaison(&e);
//	ft_printf("avant push_back_chemin\n");
	if (!(e.chemin = push_back_chemin(e.chemin)))
	{
		fin_lemin(&e);
		ft_printf_fd(2, "ERROR\n");
		return (0);
	}
//	ft_printf("avant push_back_lem1\n");
	if (!(e.chemin->chemin = push_back_lem1(e.chemin->chemin, e.start1)))
	{
		fin_lemin(&e);
		ft_printf_fd(2, "ERROR\n");
		return (0);
	}
//	ft_printf("avant create_chemin\n");
	create_chemin(&e);
//	ft_printf("avant print_chemin\n");
//	ft_print_chemin(&e);
//	ft_printf("%d\n", e.nb_chemin);
	del_chemin(&e);
	if (e.nb_chemin == 0)
	{
		fin_lemin(&e);
		ft_printf_fd(2, "ERROR\n");
		return (0);
	}
//	ft_print_chemin(&e);
//	ft_printf("%d\n", e.nb_chemin);
//	ft_printf("avant convert_chemin\n");
	if (!convert_chemin(&e))
	{
		fin_lemin(&e);
		ft_printf_fd(2, "ERROR\n");
		return (0);
	}
//	ft_printf("avant printf_convert_chemin\n");
//	ft_print_convert_chemin(&e);
	invalid_chemin(&e);
	if (!create_order(&e))
	{
		fin_lemin(&e);
		ft_printf_fd(2, "ERROR\n");
		return (0);
	}
//	ft_print_convert_chemin(&e);
	if (!parcours(&e))
	{
		fin_lemin(&e);
		ft_printf_fd(2, "ERROR\n");
		return (0);
	}
	fin_lemin(&e);
	return (0);
}
