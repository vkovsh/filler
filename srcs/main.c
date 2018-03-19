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

int			main(void)
{
	int		fd;
	t_list	*lst;

	lst = NULL;
	read_from_output(&lst);
	parse_output(lst);
	while (1)
		ft_printf("%d %d\n", 1, 1);
	return (0);
}
