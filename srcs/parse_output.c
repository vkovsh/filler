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

#include "filler.h"

static inline t_bool	is_first_turn(const char *first_str)
{
	if (*first_str == '#')
		return (TRUE);
	return (FALSE);
}

static void				get_height_and_width(char *str, t_filler *filler)
{
	char				**parsed;

	parsed = ft_strsplit(str, ' ');
	filler->rows = ft_atoi(parsed[1]);
	filler->cols = ft_atoi(parsed[2]);
	ft_strdel(&(parsed[0]));
	ft_strdel(&(parsed[1]));
	ft_strdel(&(parsed[2]));
	free(parsed);
}

static inline void		init_filler_field(t_filler *filler)
{
	int					i;

	i = -1;
	filler->rows  = (char **)malloc(sizeof(char *) * filler->rows); 
	while (++i < filler->rows)
		(filler->field)[i] = ft_strnew(filler->cols);
}

static void				init_filler(t_list **lst, t_filler *filler)
{
	t_list				*tmp;
	char				*tmp_str;

	tmp = *lst;
	tmp = ((((tmp->next)->next)->next)->next)->next;
	tmp_str = (char *)(tmp->cintent);
	if (ft_strstr(tmp_str, "vkovsh"))
	{
		filler->player = player_one;
		filler->is_turn = TRUE;
	}
	else
	{
		filler->player = player_two;
		filler->is_turn = FALSE;
	}
	tmp = (((tmp->next)->next)->next)->next;
	get_height_and_width((char *)(tmp->content), filler);
	tmp = (tmp->next)->next;
	*lst = tmp;
	init_filler_field(filler);
}

void					skip_while_not_field(t_list **lst)
{
	t_list				*tmp;

	tmp = *lst;
	tmp = ((tmp->next)->next)->next;
	*lst = tmp;
}

void					read_new_field(t_list **lst, t_filler *filler)
{
	int					i;
	t_list				*tmp;
	char				*str_cpy;

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

void					read_new_piece(t_list **lst, t_filler *filler)
{
	t_list				*tmp;
	char				*init_str;
	char				**split;
	int					i;

	tmp = *lst;
	init_str = tmp->content;
	split = ft_strsplit(init_str, ' ');
	ft_strdel(&(split[0]));
	filler->piece.rows = ft_atoi(split[1]);
	ft_strdel(&(split[1]));
	filler->piece.cols = ft_atoi(split[2]);
	ft_strdel(&(split[2]));
	free(split);
	filler->piece.container = (char **)malloc(sizeof(char *) *
			filler->piece.cols);
	i = -1;
	while (++i < filler->piece.rows)
	{
		(filler->piece.container)[i] = 
	}
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
