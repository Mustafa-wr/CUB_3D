/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:59:33 by bammar            #+#    #+#             */
/*   Updated: 2023/05/17 01:41:19 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

#ifdef Linux
typedef enum key_map
{
	ON_DESTROY = 36,
	ESC = 65307,
	KEY_UP = 65362,
	KEY_DOWN = 65364,
	KEY_RIGHT = 65363,
	KEY_LEFT = 65361,
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100
}					t_key_map;
#else
typedef enum key_map
{
	ON_DESTROY = 17,
	ESC = 53,
	KEY_UP = 126,
	KEY_DOWN = 125,
	KEY_RIGHT = 124,
	KEY_LEFT = 123,
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2
}					t_key_map;
#endif

typedef enum colors
{
	RED = 0xFF0000,
	BLUE = 0x0000FF,
	GRN = 0x00FF00,
	WHT = 0xFFFFFF
}		t_colors;

typedef enum e_side
{
	HOR,
	VER
}	t_side;

#endif
