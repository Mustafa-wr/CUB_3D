/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:59:51 by bammar            #+#    #+#             */
/*   Updated: 2023/05/25 16:53:21 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// horizontals are even (wall_count % 2 == 0)
void set_sqaures(t_hook_vars *hook)
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
			if (hook->game->path[i][j] != '1' && hook->game->path[i][j] != '2')
				continue ;
			s.x = j * hook->side_length;
			s.y = i * hook->side_length;
			hook->walls[hook->wall_count].start = s;
			hook->walls[hook->wall_count].end = (t_point){
				s.x + hook->side_length, s.y};
			hook->walls[hook->wall_count].hide = hook->game->path[i][j] == '2';
			hook->walls[++hook->wall_count].start = s;
			hook->walls[hook->wall_count].end = (t_point){
				s.x, s.y + hook->side_length};
			hook->walls[hook->wall_count].hide = hook->game->path[i][j] == '2';
			hook->walls[++hook->wall_count].start = (t_point){
				s.x, s.y + hook->side_length};
			hook->walls[hook->wall_count].end = (t_point){
				s.x + hook->side_length, s.y + hook->side_length};
			hook->walls[hook->wall_count].hide = hook->game->path[i][j] == '2';
			hook->walls[++hook->wall_count].start = (t_point){
				s.x + hook->side_length, s.y};
			hook->walls[hook->wall_count].end = (t_point){
				s.x + hook->side_length, s.y + hook->side_length};
			hook->walls[hook->wall_count++].hide = hook->game->path[i][j] == '2';
		}
	}
}

void	walls_init(t_hook_vars *hook)
{
	hook->walls = malloc(sizeof(t_wall) * 4
		* ((hook->game->width * hook->game->height) + 1));
	if (!hook->walls)
		exit(EXIT_FAILURE);
	hook->wall_count = 0;
	set_sqaures(hook);
}
