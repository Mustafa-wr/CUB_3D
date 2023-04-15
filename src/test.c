/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 01:48:27 by mradwan           #+#    #+#             */
/*   Updated: 2023/04/16 02:26:47 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <limits.h>
#include "cub3d.h"

#define TWO_PI (2 * M_PI)
#define FOV_ANGLE 60 * (M_PI / 180) // Field of view angle in radians
#define NUM_RAYS 640				// Number of rays to cast
#define WALL_STRIP_WIDTH 1			// Width of a wall strip in pixels

typedef struct s_ray
{
	float angle;	  // Angle of the ray in radians
	float distance;	  // Distance of the ray to the wall hit
	int hit_vertical; // Flag indicating if the ray hit a vertical wall
	int wall_hit_x;	  // X coordinate of the wall hit
	int wall_hit_y;	  // Y coordinate of the wall hit
} t_ray;

// void cast_rays(float player_x, float player_y, float player_angle, char **map)
// {
// 	t_ray rays[NUM_RAYS];					  // Array to store the rays
// 	float ray_angle;						  // Angle of each ray
// 	float x_intercept, y_intercept;			  // Coordinates of the first wall intersection for each ray
// 	float x_step, y_step;					  // Distance between each intersection for each ray
// 	float next_x_intercept, next_y_intercept; // Coordinates of the next intersection for each ray
// 	float x_hit_distance, y_hit_distance;	  // Distance to the nearest wall in each direction
// 	float hit_distance;						  // Distance to the nearest wall overall
// 	int wall_hit_x, wall_hit_y;				  // Coordinates of the nearest wall hit
// 	int i, j;

// 	// Initialize rays
// 	ray_angle = player_angle - (FOV_ANGLE / 2);
// 	for (i = 0; i < NUM_RAYS; i++)
// 	{
// 		rays[i].angle = ray_angle;
// 		rays[i].distance = -1;
// 		rays[i].hit_vertical = 0;
// 		ray_angle += FOV_ANGLE / NUM_RAYS;
// 	}

// 	// Cast rays
// 	for (i = 0; i < NUM_RAYS; i++)
// 	{
// 		// Find x and y step directions based on ray angle
// 		int going_right = rays[i].angle > 0 && rays[i].angle < M_PI;
// 		int going_up = rays[i].angle > (M_PI / 2) && rays[i].angle < (3 * M_PI / 2);
// 		x_step = WALL_STRIP_WIDTH / tan(rays[i].angle);
// 		x_step *= going_right ? 1 : -1;
// 		y_step = WALL_STRIP_WIDTH * tan(rays[i].angle);
// 		y_step *= going_up ? -1 : 1;

// 		// Find the first intersection
// 		x_intercept = floor(player_x / WALL_STRIP_WIDTH) * WALL_STRIP_WIDTH;
// 		x_intercept += going_right ? WALL_STRIP_WIDTH : 0;
// 		y_intercept = player_y + (x_intercept - player_x) * tan(rays[i].angle);

// 		// Find the step increments
// 		next_x_intercept = x_step + x_intercept;
// 		next_y_intercept = y_step + y_intercept;

// 		// Check for horizontal intersections
// 		x_hit_distance = INT_MAX;
// 		while (next_x_intercept >= 0 && next_x_intercept <= 640 &&
// 			   next_y_intercept >= 0 && next_y_intercept <= 480)
// 		{
// 			j = (int)(next_y_intercept / WALL_STRIP_WIDTH);
// 			i = going_right ? (int)(next_x_intercept / WALL_STRIP_WIDTH) : (int)(next_x_intercept / WALL_STRIP_WIDTH) - 1;
// 			if (map[j][i] == '1')
// 			{
// 				x_hit_distance = fabs(next_x_intercept - player_x) / cos(rays[i].angle);
// 				wall_hit_x = (int)next_x_intercept;
// 				wall_hit_y = (int)next_y_intercept;
// 				break;
// 			}
// 			else
// 			{
// 				next_x_intercept += x_step;
// 				next_y_intercept += y_step;
// 			}
// 		}

// 		// Check for vertical intersections
// 		y_hit_distance = INT_MAX;
// 		while (next_x_intercept >= 0 && next_x_intercept <= 640 &&
// 			   next_y_intercept >= 0 && next_y_intercept <= 480)
// 		{
// 			i = (int)(next_x_intercept / WALL_STRIP_WIDTH);
// 			j = going_up ? (int)(next_y_intercept / WALL_STRIP_WIDTH) - 1 : (int)(next_y_intercept / WALL_STRIP_WIDTH);
// 			if (map[j][i] == '1')
// 			{
// 				y_hit_distance = fabs(next_y_intercept - player_y) / sin(rays[i].angle);
// 				wall_hit_x = (int)next_x_intercept;
// 				wall_hit_y = (int)next_y_intercept;
// 				rays[i].hit_vertical = 1;
// 				break;
// 			}
// 			else
// 			{
// 				next_x_intercept += x_step;
// 				next_y_intercept += y_step;
// 			}
// 		}

// 		// Record the nearest wall hit
// 		hit_distance = fmin(x_hit_distance, y_hit_distance);
// 		rays[i].distance = hit_distance;
// 		rays[i].wall_hit_x = wall_hit_x;
// 		rays[i].wall_hit_y = wall_hit_y;
// 	}

// 	// Print the distances for debugging
// 	for (i = 0; i < NUM_RAYS; i++)
// 	{
// 		printf("%f\n", rays[i].distance);
// 	}
// }

float normalize_angle(float angle)
{
    angle = fmodf(angle, TWO_PI);  // Get the angle modulo 2π
    if (angle < 0) {
        angle += TWO_PI;  // Add 2π if the angle is negative
    }
    return angle;
}

float *cast_rays(float player_x, float player_y, float player_angle, char **map, int map_width, int map_height)
{
	int i, j;
	float ray_angle, x_step, y_step, next_x_intercept, next_y_intercept, x_hit_distance, y_hit_distance;
	int wall_hit_x, wall_hit_y;
	int going_up, going_left;
	t_ray rays[NUM_RAYS];
	float *distances = malloc(NUM_RAYS * sizeof(float));

	// Initialize the rays
	ray_angle = player_angle - (FOV_ANGLE / 2);
	for (i = 0; i < NUM_RAYS; i++)
	{
		rays[i].angle = normalize_angle(ray_angle);
		printf("%f\n", rays[i].angle);
		rays[i].distance = INT_MAX;
		rays[i].hit_vertical = 0;
		ray_angle += FOV_ANGLE / NUM_RAYS;
	}

	// Cast each ray and find the nearest wall hit
	for (i = 0; i < NUM_RAYS; i++)
	{
		going_up = rays[i].angle > 0 && rays[i].angle < M_PI;
		going_left = rays[i].angle > M_PI_2 && rays[i].angle < 3 * M_PI_2;
		x_step = WALL_STRIP_WIDTH / tan(rays[i].angle);
		x_step *= going_left ? -1 : 1;
		y_step = WALL_STRIP_WIDTH / tan(M_PI_2 - rays[i].angle);
		y_step *= going_up ? -1 : 1;

		next_x_intercept = (int)(player_x / WALL_STRIP_WIDTH) * WALL_STRIP_WIDTH;
		next_x_intercept += going_left ? -0.0001 : WALL_STRIP_WIDTH;
		next_y_intercept = player_y + (next_x_intercept - player_x) * tan(rays[i].angle);

		// Check for horizontal intersections
		x_hit_distance = INT_MAX;
		while (next_x_intercept >= 0 && next_x_intercept <= map_width * WALL_STRIP_WIDTH &&
			   next_y_intercept >= 0 && next_y_intercept <= map_height * WALL_STRIP_WIDTH)
		{
			j = (int)(next_y_intercept / WALL_STRIP_WIDTH);
			i = going_left ? (int)(next_x_intercept / WALL_STRIP_WIDTH) - 1 : (int)(next_x_intercept / WALL_STRIP_WIDTH);
			if (map[j][i] == '1')
			{
				x_hit_distance = fabs(next_x_intercept - player_x) / cos(rays[i].angle);
				wall_hit_x = (int)next_x_intercept;
				wall_hit_y = (int)next_y_intercept;
				break;
			}
			next_x_intercept += going_left ? -WALL_STRIP_WIDTH : WALL_STRIP_WIDTH;
			next_y_intercept += y_step;
		}

		// Check for vertical intersections
		y_hit_distance = INT_MAX;
		next_y_intercept = (int)(player_y / WALL_STRIP_WIDTH) * WALL_STRIP_WIDTH;
		next_y_intercept += going_up ? -0.0001 : WALL_STRIP_WIDTH;
		next_x_intercept = player_x + (next_y_intercept - player_y) / tan(rays[i].angle);
		while (next_x_intercept >= 0 && next_x_intercept <= map_width * WALL_STRIP_WIDTH &&
			   next_y_intercept >= 0 && next_y_intercept <= map_height * WALL_STRIP_WIDTH)
		{
			i = (int)(next_x_intercept / WALL_STRIP_WIDTH);
			j = going_up ? (int)(next_y_intercept / WALL_STRIP_WIDTH) - 1 : (int)(next_y_intercept / WALL_STRIP_WIDTH);
			if (map[j][i] == '1')
			{
				y_hit_distance = fabs(next_y_intercept - player_y) / sin(rays[i].angle);
				wall_hit_x = (int)next_x_intercept;
				wall_hit_y = (int)next_y_intercept;
				rays[i].hit_vertical = 1;
				break;
			}
			next_x_intercept += x_step;
			next_y_intercept += going_up ? -WALL_STRIP_WIDTH : WALL_STRIP_WIDTH;
		}

		// Choose the nearest hit distance
		if (x_hit_distance < y_hit_distance)
		{
			rays[i].distance = x_hit_distance;
		}
		else
		{
			rays[i].distance = y_hit_distance;
		}
	}

	// Store the distances in the array and return it
	for (i = 0; i < NUM_RAYS; i++)
	{
		distances[i] = rays[i].distance;
	}
	return distances;
}




// static void	add_until_wall(t_ray *ray, t_cub3d *map, float ray_offset[2])
// {
// 	int	x;
// 	int	y;

// 	while (true)
// 	{
// 		x = ray->end[0] / 32;
// 		y = ray->end[1] / 32;
// 		if (x < 0 || y < 0 || x >= map->width
// 			|| y >= map->height || map->path[y][x] == '1'
// 			|| map->path[y][x] == '8' || map->path[y][x] == '9'
// 			|| map->path[y][x] == '7' || map->path[y][x] == 'X')
// 			break ;
// 		ray->end[0] += ray_offset[0];
// 		ray->end[1] += ray_offset[1];
// 	}
// }

// static float	calc_horizontal(t_ray *ray, t_cub3d *map, int x, int y)
// {
// 	float	tan_v;
// 	float	ray_offset[2];

// 	tan_v = -1 / tan(ray->ra);
// 	if (ray->ra < (float)M_PI && ray->ra > 0)
// 	{
// 		ray->end[1] = y / 32 * 32 + 32;
// 		ray->end[0] = (y - ray->end[1]) * tan_v + x;
// 		ray_offset[1] = 32;
// 	}
// 	else if (ray->ra > (float)M_PI && ray->ra != (float)M_PI * 2)
// 	{
// 		ray->end[1] = y / 32 * 32 - 0.0001f;
// 		ray->end[0] = (y - ray->end[1]) * tan_v + x;
// 		ray_offset[1] = -32;
// 	}
// 	if (ray->ra == 0 || ray->ra == (float)M_PI)
// 	{
// 		ray->end[0] = x;
// 		ray->end[1] = y;
// 		return (MAXFLOAT);
// 	}
// 	ray_offset[0] = -ray_offset[1] * tan_v;
// 	add_until_wall(ray, map, ray_offset);
// 	return (sqrtf(powf((ray->end[0] - x), 2) + powf((ray->end[1] - y), 2)));
// }

// static float	calc_vertical(t_ray *ray, t_cub3d *map, int x, int y)
// {
// 	float	tan_v;
// 	float	ray_offset[2];

// 	tan_v = -tan(ray->ra);
// 	if (ray->ra > (float)M_PI_2 && ray->ra < (3 * (float)M_PI_2))
// 	{
// 		ray->end[0] = x / 32 * 32 - 0.0001f;
// 		ray_offset[0] = -32;
// 	}
// 	else if (ray->ra < (float)M_PI_2 || ray->ra > (3 * (float)M_PI_2))
// 	{
// 		ray->end[0] = x / 32 * 32 + 32;
// 		ray_offset[0] = 32;
// 	}
// 	ray->end[1] = (x - ray->end[0]) * tan_v + y;
// 	if (ray->ra == (float)M_PI_2 || ray->ra == (3 * (float)M_PI_2))
// 	{
// 		ray->end[0] = x;
// 		ray->end[1] = y;
// 		return (MAXFLOAT);
// 	}
// 	ray_offset[1] = -ray_offset[0] * tan_v;
// 	add_until_wall(ray, map, ray_offset);
// 	return (sqrtf(powf((ray->end[0] - x), 2) + powf((ray->end[1] - y), 2)));
// }

// float	calc_rays(t_ray *ray, t_cub3d *map, int x, int y)
// {
// 	float	dist_h;
// 	float	dist_v;
// 	int		end_h[2];

// 	ray->start[0] = x;
// 	ray->start[1] = y;
// 	dist_h = calc_horizontal(ray, map, x, y);
// 	end_h[0] = ray->end[0];
// 	end_h[1] = ray->end[1];
// 	ray->dir = 'N';
// 	dist_v = calc_vertical(ray, map, x, y);
// 	if (dist_h < dist_v)
// 	{
// 		ray->end[0] = end_h[0];
// 		ray->end[1] = end_h[1];
// 		ray->dir = 'E';
// 		return (dist_h);
// 	}
// 	return (dist_v);
// }

