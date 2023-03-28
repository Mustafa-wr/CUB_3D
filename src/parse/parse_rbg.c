/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rbg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:39:33 by mradwan           #+#    #+#             */
/*   Updated: 2023/03/28 21:28:43 by bammar           ###   ########.fr       */
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
		return (printf("Error\n"), 0);
	i = 0;
	c = 0;
	while (map->floor_tmp[i])
	{
		if (map->floor_tmp[i] == ',')
			c++;
		i++;
	}
	if (c != 2)
		return (printf("Error\n"), 0);
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

int	store_the_rpg(t_cub3d *map)
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
	printf("%d\n", map->cieling[0]);
	return (1);
}
