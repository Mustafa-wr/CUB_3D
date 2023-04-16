/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:39:33 by mradwan           #+#    #+#             */
/*   Updated: 2023/04/16 23:34:50 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_for_digits(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]) || s[i] == ',' || s[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

static int	check_for_rgb_helper(char *str, int i, int c, int tmp)
{
	while (str[i])
	{
		if (str[i] == ',')
		{
			if (i == 0)
				return (0);
			tmp = i + 1;
			while (str[tmp] == ' ')
				tmp++;
			if (str[tmp] == ',')
				return (0);
			c++;
		}
		i++;
	}
	if (c != 2)
		return (0);
	return (1);
}

static int	check_for_rbg(t_cub3d *map, int i, int c)
{
	int	tmp;

	tmp = 0;
	if (!check_for_rgb_helper(map->ceiling_tmp, i, c, tmp))
		return (0);
	i = 0;
	c = 0;
	if (!check_for_rgb_helper(map->floor_tmp, i, c, tmp))
		return (0);
	return (1);
}

static int	store_the_floor(t_cub3d *map, int i, int c, char *sub)
{
	sub = NULL;
	i = 0;
	while (map->floor_tmp[i] != ',')
		i++;
	sub = ft_substr(map->floor_tmp, 0, i);
	if (ft_strlen(sub) > 4)
		return (free(sub), 0);
	map->floor[0] = ft_atoi(sub);
	free(sub);
	i++;
	c = i;
	while (map->floor_tmp[i] != ',')
		i++;
	sub = ft_substr(map->floor_tmp, c, i);
	if (ft_strlen(sub) > 4)
		return (free(sub), 0);
	map->floor[1] = ft_atoi(sub);
	free(sub);
	c = i;
	while (map->floor_tmp[i] != ',' && map->floor_tmp[i])
		i++;
	sub = ft_substr(map->floor_tmp, c, i);
	if (ft_strlen(sub) > 4)
		return (free(sub), 0);
	map->floor[2] = ft_atoi(sub);
	free(sub);
	return (1);
}

static int	store_the_cieling(t_cub3d *map, int i, int c, char *sub)
{
	sub = NULL;
	i = 0;
	while (map->ceiling_tmp[i] != ',')
		i++;
	sub = ft_substr(map->ceiling_tmp, 0, i);
	if (ft_strlen(sub) > 4)
		return (free(sub), 0);
	map->cieling[0] = ft_atoi(sub);
	free(sub);
	i++;
	c = i;
	while (map->ceiling_tmp[i] != ',')
		i++;
	sub = ft_substr(map->ceiling_tmp, c, i);
	if (ft_strlen(sub) > 4)
		return (free(sub), 0);
	map->cieling[1] = ft_atoi(sub);
	free(sub);
	c = i;
	while (map->ceiling_tmp[i] != ',' && map->ceiling_tmp[i])
		i++;
	sub = ft_substr(map->ceiling_tmp, c, i);
	if (ft_strlen(sub) > 4)
		return (free(sub), 0);
	map->cieling[2] = ft_atoi(sub);
	free(sub);
	return (1);
}

int	store_the_rgb(t_cub3d *map)
{
	int		i;
	int		c;
	char	*sub;

	i = 0;
	c = 0;
	sub = NULL;
	if (!check_for_rbg(map, i, c) || !check_for_digits(map->ceiling_tmp) \
		|| !check_for_digits(map->floor_tmp))
		return (free_strings(map->map), ft_putendl_fd("Error", 2), 0);
	map->floor = malloc(sizeof(int) * 3);
	map->cieling = malloc(sizeof(int) * 3);
	if (!store_the_floor(map, i, c, sub) || !store_the_cieling(map, i, c, sub))
		return (free_strings(map->map), ft_putendl_fd("Error", 2), 0);
	i = 0;
	while (i < 3)
	{
		if (map->cieling[i] > 255 || map->cieling[i] < 0)
			return (free_strings(map->map), ft_putendl_fd("Error", 2), 0);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (map->floor[i] > 255 || map->floor[i] < 0)
			return (free_strings(map->map), ft_putendl_fd("Error", 2), 0);
		i++;
	}
	// printf("%d\n", map->cieling[0]);
	return (1);
}
