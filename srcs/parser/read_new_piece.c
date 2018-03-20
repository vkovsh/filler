/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_new_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:19:54 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/20 13:19:57 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		read_new_piece(t_list **lst, t_filler *filler)
{
	t_list	*tmp;
	char	*init_str;
	char	**split;
	int		i;

	tmp = *lst;
	init_str = tmp->content;
	split = ft_strsplit(init_str, ' ');
	ft_strdel(&(split[0]));
	filler->piece.rows = ft_atoi(split[1]);
	ft_strdel(&(split[1]));
	filler->piece.cols = ft_atoi(split[2]);
	ft_strdel(&(split[2]));
	free(split);
	filler->piece.container = (char **)malloc(sizeof(char *) * filler->piece.rows);
	i = -1;
	tmp = tmp->next;
	while (++i < filler->piece.rows)
	{
		(filler->piece.container)[i] = (char *)(tmp->content);
		tmp = tmp->next;
	}
	*lst = tmp;
}