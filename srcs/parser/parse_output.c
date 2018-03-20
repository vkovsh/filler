/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 16:33:56 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/19 19:24:10 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static inline t_bool	is_first_turn(const char *first_str)
{
	if (*first_str == '#')
		return (TRUE);
	return (FALSE);
}

void					skip_while_not_field(t_list **lst)
{
	t_list				*tmp;

	tmp = *lst;
	tmp = ((tmp->next)->next)->next;
	*lst = tmp;
}

void					parse_output(t_list *lst, t_filler *filler)
{
	if (is_first_turn(lst->content))
		init_filler(&lst, filler);
	else
		skip_while_not_field(&lst);
	read_new_field(&lst, filler);
	if (filler->is_turn)
	{
		read_new_piece(&lst, filler);
	}
}
