/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 04:55:17 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/06 23:59:24 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_print_help(void)
{
	ft_printf("\tHELP\n-c : Nombre de deplacement\n-t : Nombre de tour\n");
	ft_printf("-e : enlever l affichage des donnees\n");
	ft_printf("-v : Nombre de chemin utilise\n");
	ft_printf("-x : nombre de salle dans chaque chemin\n");
	ft_printf("-z : Affichage des chemins\n\n");
}
