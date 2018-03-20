/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_new_field.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:22:55 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/20 13:23:04 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		read_new_field(t_list **lst, t_filler *filler)
{
	int		i;
	t_list	*tmp;
	char	*str_cpy;

	tmp = *lst;
	i = -1;
	while (++i < filler->rows)
	{
		str_cpy = (char *)(tmp->content) + 4;
		ft_memmove((filler->field)[i], str_cpy, filler->cols);
		tmp = tmp->next;
	}
	*lst = tmp;
}