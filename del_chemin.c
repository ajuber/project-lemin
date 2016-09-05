/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_chemin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 05:14:35 by ajubert           #+#    #+#             */
/*   Updated: 2016/09/04 19:22:52 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*static void		del_one_chemin(t_free_chemin *t)
{
	t->tmp_previous->next = t->tmp_next;
	ft_free_list_lem1(&t->tmp->chemin);
}

static void		del_chemin1(t_e *e)
{
	t_l_chemin *tmp;
	t_l_chemin *tmp_previous;
	t_l_chemin *tmp_test;
	t_liste1	*t_chemin;
	t_liste1	*t_chemin1;
	t_l_chemin *tmp_test_previous;
	t_free_chemin t;

	t.tmp = e->chemin;
	t.tmp = t.tmp->next;
	t.tmp_previous = e->chemin;
	while (t.tmp->next)
	{
		t.tmp_test = t.tmp->next;
		t.tmp_test_previous = t.tmp;
		if (t.tmp_test && t.tmp_test->next)
			t.tmp_test = t.tmp_test->next;
		while (t.tmp_test)
		{
			t.t_chemin = t.tmp->chemin;
			while (t.t_chemin->next)
			{
				t.t_chemin1 = t.tmp_test->chemin;
				while (t.t_chemin1)
				{
					if (ft_strcmp(t.t_chemin->str, t.t_chemin1->str) == 0)
					{
						if (t.tmp_test->nb_salle >= t.tmp->nb_salle)
							del_one_chemin(&t);
						if (t.tmp_test->nb_salle < t.tmp->nb_salle)
							del_one_chemin1(&t);
					}
					t.t_chemin1 = t.t_chemin1->next;
				}
				t.t_chemin = t.t_chemin->next;
			}
			t.tmp_test = t.tmp_test->next;
			t.tmp_test_previous = t.tmp_test_previous->next;
		}
		t.tmp = t.tmp->next;
		t.tmp_previous = t.tmp_previous->next;
	}
}*/

void	del_chemin(t_e *e)
{
	t_l_chemin *tmp;
	t_l_chemin *tmp_previous;

	tmp = e->chemin;
	tmp_previous = e->chemin;
	if (tmp->next)
		tmp = tmp->next;
	while (tmp->next)
	{
		tmp = tmp->next;
		tmp_previous = tmp_previous->next;
	}
	ft_free_list_lem1(&tmp->chemin);
	tmp_previous->next = NULL;
//	del_chemin1(e);
}
