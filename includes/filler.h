/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 16:27:49 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/27 13:50:09 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "ft_printf.h"
# define MIN(x, y) ((x < y) ? x : y)
# define MAX(x, y) ((x > y) ? x : y)

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_player
{
	char		id;
	t_point		start;
}				t_player;

typedef struct	s_token
{
	int			width;
	int			height;
	int			size;
	char		**data;
}				t_token;

typedef struct	s_filler
{
	int			inited;
	t_player	player;
	t_player	enemy;
	t_point		target;
	t_token		board;
	t_token		token;
	t_point		*buf_p;
	int			p_count;
	t_point		*buf_e;
	int			e_count;
}				t_filler;

t_point			closest_pair(t_filler filler);
int				try_place(t_filler filler, t_point point);
void			place(t_filler filler);
int				place_around(t_filler filler, t_point p, t_point *result);
t_point			find_placement(t_filler filler);
void			read_token(char *line, int offset, t_token *token);
void			free_token(t_token *token, int offset);
void			filler_loop(t_filler filler);
void			init(t_filler *filler);
#endif
