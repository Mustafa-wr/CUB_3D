/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:59:51 by bammar            #+#    #+#             */
/*   Updated: 2023/05/13 20:07:28 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	allocate(t_hook_vars *hook)
{
	hook->bounds = malloc(sizeof(t_bound)
		* ((hook->game->width * hook->game->height) + 1));
	if (!hook->bounds)
		exit(EXIT_FAILURE);
}

// static int	set_ver_bounds(t_hook_vars *hook, int bound_count);

/**
 * start a bound when a wall is reached.
 * 	and set its end to be the start + length side
 * 	next loop if there's is still a wall (true flag)
 * 	just edit the end of last bound.
 * but if there's no wall just continue and set the flag to false.
 * returns bound count for future use. 
*/
static int	set_hor_bounds(t_hook_vars *hook, int bound_count)
{
	int		i;
	int		j;
	bool	cont;

	i = -1;
	while (++i < hook->game->height)
	{
		cont = false;
		j = -1;
		while (++j < hook->game->width - 1)
		{
			if (hook->game->path[i][j] != '1')
				cont = false;
			else if (!cont)
			{
				hook->bounds[++bound_count].start = (t_point){
					j * hook->side_length,
					i * hook->side_length
				};
				hook->bounds[bound_count].end = (t_point){
					(j + 1) * hook->side_length,
					i * hook->side_length
				};
				cont = true;
			}
			else
				hook->bounds[bound_count].end = (t_point){
					(j + 1) * hook->side_length,
					i * hook->side_length
				};
		}
	}
	return (bound_count);
}

void	bounds_init(t_hook_vars *hook)
{
	allocate(hook);
	hook->bound_count = set_hor_bounds(hook, -1);
	// bound_count = set_ver_bounds(hook, bound_count);
	// hook->bounds[bound_count] = NULL; use bound count instead.
}
