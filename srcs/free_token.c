/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 14:16:01 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/27 14:16:03 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		free_token(t_token *token, int offset)
{
	int		i;
	char	*str;

	if (!token->data)
		return ;
	i = 0;
	while (i < token->height)
	{
		str = token->data[i] - offset;
		ft_strdel(&str);
		i++;
	}
	ft_memdel((void **)&token->data);
}
