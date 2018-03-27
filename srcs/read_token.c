/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 14:09:48 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/27 14:09:51 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		read_token(char *line, int offset, t_token *token)
{
	int		i;

	free_token(token, offset);
	line = ft_strchr(line, ' ') + 1;
	token->height = ft_atoi(line);
	token->width = ft_atoi(ft_strchr(line, ' '));
	token->size = token->height * token->width;
	if (offset)
	{
		get_next_line(0, &line);
		ft_strdel(&line);
	}
	token->data = ft_memalloc(token->height * sizeof(char *));
	i = -1;
	while (++i < token->height)
	{
		get_next_line(0, &line);
		token->data[i] = line + offset;
	}
}
