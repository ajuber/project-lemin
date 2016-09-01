/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 18:22:41 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/01 03:56:26 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"

typedef struct				s_liste
{
	char					*str;
	char					*str1;
	struct s_liste			*next;
}							t_liste;

typedef struct		s_e
{
	char			*line;
	int				start;
	int				end;
	int				nb_ant;
	t_liste			*salle;
	t_liste			*liaison;
	char			***liaison1;
	char			***chemin;
}					t_e;

int					is_infos(t_e *e);
int					recup_salle(t_e *e);
int					recup_nb_ant(t_e *e);
int					is_liaison(t_e *e);
void				free_line(char **line);
int					recup_liaison(t_e *e);
void				ft_print_salle(t_e *e);
void				ft_print_liaison(t_e *e);
int					get_salle(t_e *e);
int					get_coor(t_e *e);
t_liste				*push_back_lem(t_liste *begin_list, char *str, char *str1, int s);

#endif
