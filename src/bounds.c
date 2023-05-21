/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:59:51 by bammar            #+#    #+#             */
/*   Updated: 2023/05/17 18:36:44 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// horizontals are even (bound_count % 2 == 0)

static void	set_squares_helper(t_hook_vars *hook, int i, int j, t_point *s)
{
	s->x = j * hook->side_length;
	s->y = i * hook->side_length;
	hook->bounds[hook->bound_count].start = *s;
	hook->bounds[hook->bound_count].end = (t_point){
		s->x + hook->side_length, s->y};
	hook->bounds[++hook->bound_count].start = *s;
	hook->bounds[hook->bound_count].end = (t_point){
		s->x, s->y + hook->side_length};
	hook->bounds[++hook->bound_count].start = (t_point){
		s->x, s->y + hook->side_length};
	hook->bounds[hook->bound_count].end = (t_point){
		s->x + hook->side_length, s->y + hook->side_length};
	hook->bounds[++hook->bound_count].start = (t_point){
		s->x + hook->side_length, s->y};
	hook->bounds[hook->bound_count++].end = (t_point){
		s->x + hook->side_length, s->y + hook->side_length};
}

void	set_sqaures(t_hook_vars *hook)
{
	int		i;
	int		j;
	t_point	s;

	i = -1;
	while (++i < hook->game->height)
	{
		j = -1;
		while (++j < hook->game->width)
		{
			if (hook->game->path[i][j] != '1')
				continue ;
			set_squares_helper(hook, i, j, &s);
		}
	}
}

void	bounds_init(t_hook_vars *hook)
{
	hook->bounds = malloc(sizeof(t_bound) * 4 \
		* ((hook->game->width * hook->game->height) + 1));
	if (!hook->bounds)
		exit(EXIT_FAILURE);
	hook->bound_count = 0;
	set_sqaures(hook);
}
