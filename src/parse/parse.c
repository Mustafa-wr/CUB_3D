/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:27:29 by mradwan           #+#    #+#             */
/*   Updated: 2023/03/27 01:31:29 by bammar           ###   ########.fr       */
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

void	init_the_path_utils(t_cub3d *p, t_vars *v)
{
	while(p->map[v->i][v->j])
	{
		while (p->map[v->i][v->j] == ' ')
			v->j++;
		if (p->map[v->i][v->j] == '1')
		{	
			printf("%d\n", v->i);
			v->tmp = v->i;
			while (p->map[v->tmp])
			{
				v->tmp++;
				v->len++;
			}
			break ;
		}
		else
			break ;
	}
}

int	check_path_chars(t_cub3d *p)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (p->path[i])
	{
		j = 0;
		while (p->path[i][j])
		{
			if (p->path[i][j] == ' ' || p->path[i][j] == '1' || p->path[i][j] == '0' || p->path[i][j] == 'N' || \
					p->path[i][j] == 'S' || p->path[i][j] == 'E' || p->path[i][j] == 'W' || p->path[i][j] == '\n')
				j++;
			else
				return (printf("Error\n"),0);
		}
		i++;
	}
	return (1);
}

void	init_the_path(t_cub3d *p, t_vars *v)
{
	p->path = malloc(sizeof(char *) * (v->len + 1));
	v->len = 0;
	while (p->map[v->i])
	{
		p->path[v->len] = ft_strdup(p->map[v->i]);
		v->i++;
		v->len++;
	}
	p->path[v->len] = NULL;
}

int	check_and_init_the_path(t_cub3d *p)
{
	t_vars v;
	
	v.i = 0;
	v.j = 0;
	v.len = 0;
	v.tmp = 0;
	int i = 0;
	while(p->map[v.i])
	{
		v.j = 0;
		init_the_path_utils(p, &v);
		if(v.len != 0)
			break ;
		v.i++;
	}
	if(!v.len)
		return (printf("Error\n"), 0);
	init_the_path(p, &v);
	if(!check_path_chars(p))
		return (0);
	i = 0;
	while (p->path[i])
		puts(p->path[i++]);
	return (1);
}

int	check_the_valid_char(t_cub3d *check)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (check->map[i])
	{
		x = 0;
		while (check->map[i][x])
		{
			if (ft_isalnum(check->map[i][x]) || check->map[i][x] == '\n' || check->map[i][x] == '.' \
				|| check->map[i][x] == '_' || check->map[i][x] == ',' || check->map[i][x] == ' ' || check->map[i][x] == '/')
					x++;
			else
				return (printf("Error\n") ,0);
		}
		i++;
	}
	return (1);
}

int	check_for_spaces(t_cub3d *map)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	
	while(map->path[i])
	{
		j = 0;
		while (map->path[i][j])
		{
			if(map->path[i][j] == ' ')
			{
				tmp = j;
				while (map->path[i][tmp] == ' ')
					tmp++;
				if (map->path[i][tmp] != '1')
					return (printf("Error\n"), 0);
				tmp = j;
				while (map->path[i][tmp] == ' ' && tmp > 0)
					tmp--;
				if(map->path[i][tmp] != '1' && tmp != 0)
					return (printf("Error\n"), 0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	main_parse(t_cub3d *cub, int ac, char **av)
{
	if(!file_check(ac, av) || !init_map(cub, av[1]) || !init_textures(cub) || !store_the_rpg(cub) || !check_the_valid_char(cub))
		return (0);
	if(!check_and_init_the_path(cub))
		return (0);
	if(!check_for_spaces(cub))
		return (0);
	return(1);
}


// int	main(int ac, char **av)
// {
// 	t_cub3d	cub;
	
// 	// if(!file_check(ac, av) || !init_map(&cub, av[1]) || !init_textures(&cub) || !store_the_rpg(&cub) || !check_the_valid_char(&cub))
// 	// 	return (0);
// 	// if(!check_and_init_the_path(&cub))
// 	// 	return 0;
// 	if(!main_parse(&cub, ac, av))
// 		return (0);
// }
