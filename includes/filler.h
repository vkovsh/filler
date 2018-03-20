/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:04:07 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/19 19:22:04 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "data.h"

void		parse_output(t_list *lst, t_filler *filler);
void		read_from_output(t_list **output);
t_filler	new_filler(void);
t_point		find_point(t_filler f);
#endif
