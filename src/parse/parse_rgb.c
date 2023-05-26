/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:39:33 by mradwan           #+#    #+#             */
/*   Updated: 2023/05/22 22:35:38 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	space_between_digits(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]))
		{
			while (ft_isdigit(s[i]))
				i++;
			while (s[i] && s[i] == ' ')
				i++;
			if (s[i] != ',' && s[i] != '\0')
				return (0);
		}
		if (s[i])
			i++;
	}
	return (1);
}

static int	check_for_digits(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]) || s[i] == ',' || s[i] == ' ' \
			|| s[i] == 'F' || s[i] == 'C')
			i++;
		else
			return (0);
	}
	if (!space_between_digits(s))
		return (0);
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
			if (str[tmp] == ',' || !str[tmp])
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
	if (!check_for_rgb_helper(map->cieling_tmp, i, c, tmp))
		return (0);
	i = 0;
	c = 0;
	if (!check_for_rgb_helper(map->floor_tmp, i, c, tmp))
		return (0);
	return (1);
}

int	store_the_rgb(t_cub3d *map)
{
	t_vars	v;

	v.i = 0;
	v.c = 0;
	v.sub = NULL;
	if (!check_for_rbg(map, v.i, v.c) || !check_for_digits(map->cieling_tmp) \
		|| !check_for_digits(map->floor_tmp))
		return (free_strings(map->map), free_tools(map), \
			ft_putendl_fd("Error\nincorrect", 2), 0);
	map->floor = malloc(sizeof(int) * 3);
	map->cieling = malloc(sizeof(int) * 3);
	if (!store_the_floor(map, &v) || !store_the_cieling(map, &v))
		return (free_strings(map->map), free(map->floor), free(map->cieling), \
			free_tools(map), ft_putendl_fd("Error\nincorrect", 2), 0);
	v.i = -1;
	while (++v.i < 3)
		if (map->cieling[v.i] > 255 || map->cieling[v.i] < 0)
			return (free_strings(map->map), free_tools(map), free(map->floor), free(map->cieling), \
				ft_putendl_fd("Error\nincorrect", 2), 0);
	v.i = -1;
	while (++v.i < 3)
		if (map->floor[v.i] > 255 || map->floor[v.i] < 0)
			return (free_strings(map->map), free_tools(map), free(map->floor), free(map->cieling), \
				ft_putendl_fd("Error\nincorrect", 2), 0);
	return (1);
}
