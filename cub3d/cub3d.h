/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:27:26 by mradwan           #+#    #+#             */
/*   Updated: 2023/03/18 20:10:35 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3d_H
# define CUB_3d_H

# include <stdio.h>
# include "gnl/get_next_line.h"
# include "libft/libft.h"

typedef struct s_cub3d
{
	char	**map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		y;
	int		x;
}	t_cub3d;

#endif