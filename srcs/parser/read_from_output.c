/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:58:33 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/19 14:58:36 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		read_from_output(t_list **output)
{
	char	*line;
	t_list	*new;

	line = NULL;
	new = NULL;
	while(get_next_line(0, &line) == 1)
	{
		new = ft_lstnew(line, ft_strlen(line));
		ft_lstadd(output, new);
		ft_strdel(&line);
	}
	ft_lstrev(&(*output));
}