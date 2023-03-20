/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:27:29 by mradwan           #+#    #+#             */
/*   Updated: 2023/03/20 23:10:23 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	file_check(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{	
			i++;
			if (av[1][i] == '.')
			{
				i++;
				if (av[1][i] != 'c')
					return (printf("there is no cub file\n"), 0);
				if (av[1][i] == 'c' && av[1][i + 1] == 'u'
						&& av[1][i + 2] == 'b' && av[1][i + 3] == '\0')
					return (1);
			}
		}
	}
	return (printf("there is no cub file\n"), 0);
}

static int	calcu_map(t_cub3d *map, char *k)
{
	int		fd;
	char	*line;
	int		i;

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
	i = 0;
	map->map = malloc(sizeof(char *) * (map->y + 1));
	if (!map->map)
		return (0);
	map->map[map->y] = NULL;
	return (1);
}

int	init_map(t_cub3d *map, char *k)
{
	int		fd;
	int		i;

	i = 0;
	if (!calcu_map(map, k))
		return (0);
	fd = open(k, O_RDONLY);
	if (fd < 0)
		return (0);
	while (i < map->y)
	{
		map->map[i] = get_next_line(fd);
		map->map[i][ft_strlen(map->map[i])] = '\0';
		i++;
	}
	map->x = ft_strlen(map->map[0]) - 1;
	close(fd);
	// if (!check_the_td(map) || !check_player_and_exit(map) || \
	// 	!valid_map_x(map) || !valid_map_y(map))
	// 	return (0);
	i = 0;
	// while (map->map[i])
	// 	printf("%s", map->map[i++]);
	return (1);
}

int	check_and_init_the_path(t_cub3d *p)
{
	t_vars v;
	
	v.i = 0;
	v.j = 0;
	v.len = 0;
	while(p->map[v.i])
	{
		v.j = 0;
		while(p->map[v.i][v.j])
		{
			while (p->map[v.i][v.j] == ' ')
				v.j++;
			if (p->map[v.i][v.j] == '1')
			{
				while (p->map[v.i])
				{
					v.i++;
					v.len++;
				}
				break ;
			}
			if (p->map[v.i][v.j])
				v.j++;
		}
		v.i++;
	}
	if(!v.len)
		return (printf("Error\n"), 0);
	p->path = malloc(sizeof(char *) * v.len);
	v.len = 0;
	while (p->map[v.i])
	{
		p->path[v.len] = ft_strdup(p->map[v.i]);
		v.i++;
		v.len++;
	}
	int i = 0;
	while (p->path[i])
		puts(p->path[i++]);
	return (1);
}

int	main(int ac, char **av)
{
	t_cub3d	cub;
	
	if(!file_check(ac, av) || !init_map(&cub, av[1]) || !init_textures(&cub) || !store_the_rpg(&cub))
		return (0);
	if(!check_and_init_the_path(&cub))
		return 0;
}
