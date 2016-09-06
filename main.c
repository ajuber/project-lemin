/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 18:17:56 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/06 23:10:46 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		ft_bonus(int argc, char **argv, t_e *e)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-h") == 0)
			e->b_h = 1;
		else if (ft_strcmp(argv[i], "-c") == 0)
			e->b_c = 1;
		else if (ft_strcmp(argv[i], "-t") == 0)
			e->b_t = 1;
		else if (ft_strcmp(argv[i], "-e") == 0)
			e->b_e = 1;
		else if (ft_strcmp(argv[i], "-v") == 0)
			e->b_v = 1;
		else if (ft_strcmp(argv[i], "-x") == 0)
			e->b_x = 1;
		else if (ft_strcmp(argv[i], "-z") == 0)
			e->b_z = 1;
		else
			return (0);
		i++;
	}
	return (1);
}

static void		under(t_e *e)
{
	if (e->b_h)
		ft_print_help();
	if (!recup_donnee(e))
		ft_print_error(e);
	if (!recup_nb_ant(e))
		ft_print_error(e);
	if (!recup_salle(e))
		ft_print_error(e);
	if (!no_start_no_end(e))
		ft_print_error(e);
	if (!recup_liaison(e))
		ft_print_error(e);
	if (!convert_liaison(e))
		ft_print_error(e);
	if (!(e->chemin = push_back_chemin(e->chemin)))
		ft_print_error(e);
	if (!(e->chemin->chemin = push_back_lem1(e->chemin->chemin, e->start1)))
		ft_print_error(e);
	create_chemin(e);
	if (e->nb_chemin == 0)
		ft_print_error(e);
	del_chemin(e);
}

static void		print_bonus(t_e *e)
{
	if (e->b_c)
		ft_printf("\nNombre de deplacement : %d\n", e->nb_deplacement);
	if (e->b_t)
		ft_printf("\nNombre de tour : %d\n", e->nb_tour);
	if (e->b_v)
		ft_printf("\nNombre de chemin utilise : %d\n", calc_nb_chemin(e));
	if (e->b_x && !e->b_z)
		print_nb_salle(e);
	if (e->b_z)
		ft_print_chemin(e);
}

int				main(int argc, char **argv)
{
	t_e e;

	ft_bzero(&e, sizeof(t_e));
	e.chemin = NULL;
	if (argc > 1)
		if (!ft_bonus(argc, argv, &e))
		{
			ft_printf_fd(2, "Mauvaise option\n");
			return (0);
		}
	under(&e);
	if (!convert_chemin(&e))
		ft_print_error(&e);
	invalid_chemin(&e);
	if (!create_order(&e))
		ft_print_error(&e);
	if (!parcours(&e))
		ft_print_error(&e);
	print_bonus(&e);
	fin_lemin(&e);
	return (0);
}
