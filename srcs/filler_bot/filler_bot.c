/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_bot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:20:25 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/20 16:20:27 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_bool	is_only_one_intersection(int x, int y, int i, int j, t_filler f)
{
	int 		x_p;
	int 		y_p;

	x_p = -1;
	while (++x_p < f.piece.rows)
	{
		y_p = -1;
		while (++y_p < f.piece.cols)
		{
			if (x_p == i && y_p == j)
				continue ;
			if (f.piece.container[x_p][y_p] == '*')
			{
				if (x + (x_p - i) < 0 || x + (x_p - i) >= f.rows ||
					y + (y_p - j) < 0 || y + (y_p - j) >= f.cols ||
					f.field[x + x_p - i][y + y_p - j] == f.small_marker ||
					f.field[x + x_p - i][y + y_p - j] == f.big_marker)
				{
					//field overflow or second intersection
					return (FALSE);
				}
			}
		}
	}
	return (TRUE);
}

static t_bool	is_correct_input(int x, int y, t_filler f)
{
	int 		i;
	int 		j;

	i = -1;
	while (++i < f.piece.rows)
	{
		j = -1;
		while (++j < f.piece.cols)
		{
			if ((f.piece.container)[i][j] == '.')
				continue ;
			if (is_only_one_intersection(x, y, i, j, f))
				return (TRUE);
		}
	}
	return (FALSE);
}

t_point			find_point(t_filler f)
{
	t_point		point;
	int			i;
	int			j;

	ft_memset((void *)(&point), 0, sizeof(point));
	i = -1;
	while (++i < f.rows)
	{
		j = -1;
		while (++j < f.cols)
		{
			if ((f.field)[i][j] == f.small_marker || (f.field)[i][j] == f.big_marker)
			{
				if (is_correct_input(i, j, f))
				{
					point.x = i;
					point.y = j;
					return (point);
				}
			}
		}
	}
	point.x = 0;
	point.y = 0;
	return (point);
}
