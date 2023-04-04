/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:39:33 by mradwan           #+#    #+#             */
/*   Updated: 2023/04/04 18:17:12 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_for_rbg(t_cub3d *map, int i, int c)
{
	while (map->ceiling_tmp[i])
	{
		if (map->ceiling_tmp[i] == ',')
			c++;
		i++;
	}
	if (c != 2)
		return (free_strings(map->map), printf("Error\n"), 0);
	i = 0;
	c = 0;
	while (map->floor_tmp[i])
	{
		if (map->floor_tmp[i] == ',')
			c++;
		i++;
	}
	if (c != 2)
		return (free_strings(map->map), printf("Error\n"), 0);
	return (1);
}

static void	store_the_floor(t_cub3d *map, int i, int c, char *sub)
{
	sub = NULL;
	i = 0;
	while (map->floor_tmp[i] != ',')
		i++;
	sub = ft_substr(map->floor_tmp, 0, i);
	map->floor[0] = ft_atoi(sub);
	free(sub);
	i++;
	c = i;
	while (map->floor_tmp[i] != ',')
		i++;
	sub = ft_substr(map->floor_tmp, c, i);
	map->floor[1] = ft_atoi(sub);
	free(sub);
	c = i;
	while (map->floor_tmp[i] != ',' && map->floor_tmp[i])
		i++;
	sub = ft_substr(map->floor_tmp, c, i);
	map->floor[2] = ft_atoi(sub);
	free(sub);
}

static void	store_the_cieling(t_cub3d *map, int i, int c, char *sub)
{
	sub = NULL;
	i = 0;
	while (map->ceiling_tmp[i] != ',')
		i++;
	sub = ft_substr(map->ceiling_tmp, 0, i);
	map->cieling[0] = ft_atoi(sub);
	free(sub);
	i++;
	c = i;
	while (map->ceiling_tmp[i] != ',')
		i++;
	sub = ft_substr(map->ceiling_tmp, c, i);
	map->cieling[1] = ft_atoi(sub);
	free(sub);
	c = i;
	while (map->ceiling_tmp[i] != ',' && map->ceiling_tmp[i])
		i++;
	sub = ft_substr(map->ceiling_tmp, c, i);
	map->cieling[2] = ft_atoi(sub);
	free(sub);
}

int	store_the_rgb(t_cub3d *map)
{
	int		i;
	int		c;
	char	*sub;

	i = 0;
	c = 0;
	sub = NULL;
	if (!check_for_rbg(map, i, c))
		return (0);
	map->floor = malloc(sizeof(int) * 3);
	map->cieling = malloc(sizeof(int) * 3);
	store_the_floor(map, i, c, sub);
	store_the_cieling(map, i, c, sub);
	i = 0;
	while (i < 3)
	{
		if (map->cieling[i] > 255 || map->cieling[i] < 0)
			return (ft_putendl_fd("Error", 2), 0);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (map->floor[i] > 255 || map->floor[i] < 0)
			return (ft_putendl_fd("Error", 2), 0);
		i++;
	}
	printf("%d\n", map->cieling[0]);
	return (1);
}
