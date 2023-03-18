/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:27:29 by mradwan           #+#    #+#             */
/*   Updated: 2023/03/18 22:20:08 by mradwan          ###   ########.fr       */
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

int	init_textures(t_cub3d *textures)
{
	int		i;
	int		flag;
	char	*tmp;

	i = 0;
	flag = 0;
	int j = 0;
	while (textures->map[i])
	{
		j = 0;
		while (textures->map[i][j] && (textures->map[i][j] == ' ' || textures->map[i][j] == '\t'))
			j++;
		printf("%d\n", flag);
		if (flag == 4)
			break ;
		if (ft_strncmp(textures->map[i] + j, "NO", 2) == 0)
		{
			tmp = ft_strchr(textures->map[i], '.');
			textures->no = ft_strdup(tmp);
			puts(textures->no);
			i = 0;
			flag++;
		}
		else if(ft_strncmp(textures->map[i] + j, "SO", 2) == 0)
		{
			tmp = ft_strchr(textures->map[i], '.');
			textures->so = ft_strdup(tmp);
			puts(textures->so);
			i = -1;
			flag++;
		}
		else if(ft_strncmp(textures->map[i] + j, "WE", 2) == 0)
		{
			tmp = ft_strchr(textures->map[i], '.');
			textures->we = ft_strdup(tmp);
			puts(textures->we);
			i = -1;
			flag++;
		}
		else if(ft_strncmp(textures->map[i] + j, "EA", 2 == 0))
		{
			tmp = ft_strchr(textures->map[i], '.');
			textures->ea = ft_strdup(tmp);
			i = -1;
			puts(textures->ea);
			flag++;
		}
		i++;
	}
	if(flag != 4)
	{
		printf("Error\n");
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_cub3d	cub;
	
	if(!file_check(ac, av) || !init_map(&cub, av[1]) || !init_textures(&cub))
		return (0);
}
