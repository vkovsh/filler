/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_filler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:15:50 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/20 13:15:52 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static inline void	get_height_and_width(char *str, t_filler *filler)
{
	char			**parsed;

	parsed = ft_strsplit(str, ' ');
	filler->rows = ft_atoi(parsed[1]);
	filler->cols = ft_atoi(parsed[2]);
	ft_strdel(&(parsed[0]));
	ft_strdel(&(parsed[1]));
	ft_strdel(&(parsed[2]));
	free(parsed);
}

static inline void	init_filler_field(t_filler *filler)
{
	int				i;

	i = -1;
	filler->field  = (char **)malloc(sizeof(char *) * filler->rows); 
	while (++i < filler->rows)
	{
		(filler->field)[i] = ft_strnew(filler->cols);
		ft_memset((filler->field)[i], '.', filler->cols);
	}
}

void				init_filler(t_list **lst, t_filler *filler)
{
	t_list			*tmp;
	char			*tmp_str;

	tmp = *lst;
	tmp = ((((tmp->next)->next)->next)->next)->next;
	tmp_str = (char *)(tmp->content);
	if (ft_strstr(tmp_str, "vkovsh"))
	{
		filler->player = player_one;
		filler->small_marker = 'o';
		filler->big_marker = 'O';
		filler->is_turn = TRUE;
	}
	else
	{
		filler->player = player_two;
		filler->small_marker = 'x';
		filler->big_marker = 'X';
		filler->is_turn = FALSE;
	}
	tmp = (((tmp->next)->next)->next)->next;
	get_height_and_width((char *)(tmp->content), filler);
	tmp = (tmp->next)->next;
	*lst = tmp;
	init_filler_field(filler);
}
