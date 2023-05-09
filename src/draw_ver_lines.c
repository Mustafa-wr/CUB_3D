/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ver_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:50:19 by bammar            #+#    #+#             */
/*   Updated: 2023/05/09 21:20:25 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d.h"

// /**
//  * @brief draws the vertical lines
//  * @param hook_vars 
//  */
// void	draw_ver_lines(t_hook_vars *hook_vars)
// {
// 	int	ray;
// 	int	ray_angle;
// 	double da;
// 	t_raycast_res res;

// 	ray = SWIDTH / 2;
// 	da = DELTA_ANGLE;
// 	ray_angle = (hook_vars->player->angle * PI / 180) - (FOV / 2) + 0.0001;
// 	while (ray > 0)
// 	{
// 		send_ray(&res, hook_vars->game, (t_vec){
// 				hook_vars->player->p,
// 				ray_angle
// 			});
// 		double proj_height = SWIDTH / 2.0 / tan(FOV/2) / (res.length + 0.0001);
// 		draw_rect(hook_vars->mlx_vars->main_img, 
// 			(t_point){ray * SCALE, SHEIGHT / 2 - (int)(proj_height / 2)},
// 			(t_size){SCALE, proj_height}, WHT);
// 		ray_angle += da;
// 		ray--;
// 	}
// }