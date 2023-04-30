/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 17:39:47 by mradwan           #+#    #+#             */
/*   Updated: 2023/05/01 03:33:40 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	store_floor_helper(t_cub3d *map, t_vars *v)
{
	v->i = 0;
	while (map->floor_tmp[v->i] == '0')
		v->i++;
	v->c = v->i;
	while (map->floor_tmp[v->i] != ',' && map->floor_tmp[v->i] != ' ')
		v->i++;
	v->sub = ft_substr(map->floor_tmp, v->c, v->i++ - v->c);
	if (ft_strlen(v->sub) > 3)
		return (free(v->sub), 0);
	map->floor[0] = ft_atoi(v->sub);
	free(v->sub);
	while (map->floor_tmp[v->i] == ' ')
		v->i++;
	if (map->floor_tmp[v->i] == ',' || map->floor_tmp[v->i] == ' ')
		v->i++;
	else
		return (0);
	while (map->floor_tmp[v->i] == ' ')
		v->i++;
	while (map->floor_tmp[v->i] == '0')
		v->i++;
	v->c = v->i;
	while (map->floor_tmp[v->i] != ',' && map->floor_tmp[v->i] != ' ')
		v->i++;
	v->sub = ft_substr(map->floor_tmp, v->c, v->i++ - v->c);
	if (ft_strlen(v->sub) > 3)
		return (free(v->sub), 0);
	return (1);
}

int	store_the_floor(t_cub3d *map, t_vars *v)
{
	if (!store_floor_helper(map, v))
		return (0);
	map->floor[1] = ft_atoi(v->sub);
	free(v->sub);
	while (map->floor_tmp[v->i] == ' ')
		v->i++;
	if (map->floor_tmp[v->i] == ',' || map->floor_tmp[v->i] == ' ')
		v->i++;
	else
		return (0);
	while (map->floor_tmp[v->i] == ' ')
		v->i++;
	while (map->floor_tmp[v->i] == '0')
		v->i++;
	v->c = v->i;
	while (map->floor_tmp[v->i] != ',' && map->floor_tmp[v->i])
		v->i++;
	v->sub = ft_substr(map->floor_tmp, v->c, v->i - v->c);
	if (ft_strlen(v->sub) > 3)
		return (free(v->sub), 0);
	map->floor[2] = ft_atoi(v->sub);
	free(v->sub);
	return (1);
}

static int	store_cieling_helper(t_cub3d *map, t_vars *v)
{
	v->i = 0;
	while (map->cieling_tmp[v->i] == '0')
		v->i++;
	v->c = v->i;
	while (map->cieling_tmp[v->i] != ',' && map->cieling_tmp[v->i] != ' ')
		v->i++;
	v->sub = ft_substr(map->cieling_tmp, v->c, v->i++ - v->c);
	if (ft_strlen(v->sub) > 3)
		return (free(v->sub), 0);
	map->cieling[0] = ft_atoi(v->sub);
	free(v->sub);
	while (map->cieling_tmp[v->i] == ' ')
		v->i++;
	if (map->cieling_tmp[v->i] == ',' || map->cieling_tmp[v->i] == ' ')
		v->i++;
	else
		return (0);
	while (map->cieling_tmp[v->i] == ' ')
		v->i++;
	while (map->cieling_tmp[v->i] == '0')
		v->i++;
	v->c = v->i;
	while (map->cieling_tmp[v->i] != ',' && map->cieling_tmp[v->i] != ' ')
		v->i++;
	v->sub = ft_substr(map->cieling_tmp, v->c, v->i++ - v->c);
	if (ft_strlen(v->sub) > 3)
		return (free(v->sub), 0);
	return (1);
}

int	store_the_cieling(t_cub3d *map, t_vars *v)
{
	if (!store_cieling_helper(map, v))
		return (0);
	map->cieling[1] = ft_atoi(v->sub);
	free(v->sub);
	while (map->cieling_tmp[v->i] == ' ')
		v->i++;
	if (map->cieling_tmp[v->i] == ',' || map->cieling_tmp[v->i] == ' ')
		v->i++;
	else
		return (0);
	while (map->cieling_tmp[v->i] == ' ')
		v->i++;
	while (map->cieling_tmp[v->i] == '0')
		v->i++;
	v->c = v->i;
	while (map->cieling_tmp[v->i] != ',' && map->cieling_tmp[v->i])
		v->i++;
	v->sub = ft_substr(map->cieling_tmp, v->c, v->i - v->c);
	if (ft_strlen(v->sub) > 3)
		return (free(v->sub), 0);
	map->cieling[2] = ft_atoi(v->sub);
	free(v->sub);
	return (1);
}
