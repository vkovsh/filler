/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 14:29:09 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/27 14:29:11 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "fcntl.h"

void		filler_loop(t_filler filler)
{
	char	*line;
	int		res;

	line = NULL;
	while ((res = get_next_line(0, &line)) != -1)
	{

		if (!line)
			continue ;
		if (!ft_strncmp(line, "Plateau ", 8))
		{
			read_token(line, 4, &(filler.board));
			if (!filler.inited)
				init(&filler);
		}
		else if (!ft_strncmp(line, "Piece ", 6))
		{
			read_token(line, 0, &(filler.token));
			place(filler);
		}
		ft_strdel(&line);
	}
}
