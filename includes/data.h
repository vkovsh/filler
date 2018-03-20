/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:49:09 by vkovsh            #+#    #+#             */
/*   Updated: 2018/03/20 13:49:11 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H
# include "ft_printf.h"

typedef struct 		s_point
{
	int 			x;
	int 			y;	
}					t_point;

typedef enum 		e_pid
{
	player_one = 1,
	player_two = 2	
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
	char			small_marker;
	char			big_marker;
}					t_filler;
#endif
