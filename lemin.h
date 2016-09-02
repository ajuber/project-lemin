/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 18:22:41 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/02 05:23:33 by ajubert          ###   ########.fr       */
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

typedef struct				s_liste1
{
	char					*str;
	struct s_liste1			*next;
}							t_liste1;

typedef struct				s_l_chemin
{
	t_liste1				*chemin;
	struct s_l_chemin		*next;
}							t_l_chemin;

typedef struct		s_e
{
	char			*line;
	int				start;
	char			*start1;
	int				end;
	char			*end1;
	int				nb_ant;
	t_liste			*salle;
	t_liste			*liaison;
	char			***liaison1;
	t_l_chemin		*chemin;
	char			***chemins;
	int				nb_liaison;
	char			*new_salle;
	int				nb_chemin;
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
t_liste1			*push_back_lem1(t_liste1 *begin_list, char *str);
int					add_infos(t_e *e);
int					no_start_no_end(t_e *e);
int					convert_liaison(t_e *e);
void				ft_print_convert_liaison(t_e *e);
int					count_list_lem(t_liste *list);
int					check_liaison(t_e *e, int i);
t_l_chemin			*push_back_chemin(t_l_chemin *begin_list);
int					add_salle(t_e *e);
int					chemin_valid(t_e *e);
int					new_chemin(t_e *e);
void				del_last_salle(t_e *e);
int					create_chemin(t_e *e);
void				ft_print_chemin(t_e *e);
void				del_chemin(t_e *e);
void				ft_free_list_lem1(t_liste1 **begin_list);

#endif
