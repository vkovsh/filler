/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 16:30:22 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/26 16:30:40 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			set_ids(t_filler *filler, char *line)
{
	filler->player.id = (line[10] == '1' ? 'O' : 'X');
	filler->enemy.id = (line[10] == '1' ? 'X' : 'O');
}

int 			main(void)
{
	t_filler	filler;
	char		*line;

	ft_bzero(&filler, sizeof(t_filler));
	line = NULL;
	filler.inited = 0;
	if (get_next_line(0, &line) && line && ft_strlen(line) > 10 &&
		!ft_strncmp(line, "$$$ exec p", 9) &&
		(line[10] == '1' || line[10] == '2'))
	{
		set_ids(&filler, line);
		ft_strdel(&line);
		filler_loop(filler);
	}
	else
		return (1);
	return (0);
}
