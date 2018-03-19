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
# include "ft_printf.h"

typedef enum 		e_pid
{
	player_one = 1,
	player_two	
}					t_pid;

typedef struct		s_piece
{
	int				rows;
	int				cols;
	char			**container;
}					t_piece;

typedef struct 		s_filler
{
	enum e_bool		is_game;
	enum e_bool 	is_turn;
	enum e_pid		player;
	char			**field;
	struct s_piece	piece;
	int				rows;
	int				cols;
}					t_filler;

void				read_from_output(t_list **output);
void				parse_output(t_list *lst, t_filler *filler);
#endif
