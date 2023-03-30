/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 01:46:05 by mradwan           #+#    #+#             */
/*   Updated: 2023/03/30 18:32:58 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	calcu_map(t_cub3d *map, char *k)
{
	int		fd;
	char	*line;

	fd = open(k, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	free(line);
	map->y = 0;
	while (line != NULL)
	{
		line = get_next_line(fd);
		free(line);
		map->y++;
	}
	close(fd);
	map->map = malloc(sizeof(char *) * (map->y + 1));
	if (!map->map)
		return (0);
	return (1);
}

int	init_map(t_cub3d *map, char *k)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	if (!calcu_map(map, k))
		return (0);
	fd = open(k, O_RDONLY);
	if (fd < 0)
		return (0);
	while (i < map->y)
	{
		line = get_next_line(fd);
		map->map[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
	}
	map->x = ft_strlen(map->map[0]) - 1;
	map->map[i] = NULL;
	i = 0;
	close(fd);
	return (1);
}
