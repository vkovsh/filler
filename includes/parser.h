/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:37:57 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/20 13:37:59 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "data.h"

void	init_filler(t_list **lst, t_filler *filler);
void	read_from_output(t_list **output);
void	read_new_field(t_list **lst, t_filler *filler);
void	read_new_piece(t_list **lst, t_filler *filler);
#endif
