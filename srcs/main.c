/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:04:57 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/19 15:22:26 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>

int				main(void)
{
	t_filler	f;
	t_list		*lst;
	t_point		p;

	lst = NULL;
	f = new_filler();
	f.is_game = TRUE;
	while (1)
	{
		read_from_output(&lst);
		parse_output(lst, &f);
		if (f.is_turn == TRUE)
		{
			f.is_turn = FALSE;
			p = find_point(f);
			ft_printf("%d %d\n", p.x, p.y);
		}
		else
			f.is_turn = TRUE;
	}
	//ft_printf("x = %[ff0000]d, y = %[ff0000]d\n", p.x, p.y);
	return (0);
}
