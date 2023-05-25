/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:27:29 by mradwan           #+#    #+#             */
/*   Updated: 2023/05/25 18:26:14 by bammar           ###   ########.fr       */
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
					return (ft_putendl_fd("Error\nthere is no cub file", 2), 0);
				if (av[1][i] == 'c' && av[1][i + 1] == 'u'
						&& av[1][i + 2] == 'b' && av[1][i + 3] == '\0')
					return (1);
			}
		}
	}
	return (ft_putendl_fd("Error\nthere is no cub file", 2), 0);
}

static int	check_the_valid_char(t_cub3d *check)
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
			if (ft_isalnum(check->map[i][x]) || check->map[i][x] == '\n' \
				|| check->map[i][x] == '.' \
					|| check->map[i][x] == '_' || check->map[i][x] == ',' || \
						check->map[i][x] == ' ' || check->map[i][x] == '/')
					x++;
			else
				return (free_strings(check->map), \
					ft_putendl_fd("Error\nincorrect", 2), 0);
		}
		i++;
	}
	return (1);
}

void	height_and_width(t_cub3d *cub)
{
	int	i;

	i = 0;
	while (cub->path[i])
		i++;
	cub->height = i;
	cub->width = ft_strlen(cub->path[0]);
}

static int	only_one_check(t_cub3d *p)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (p->path[i])
	{
		j = 0;
		while (p->path[i][j])
		{
			if (p->path[i][j] == 'N' || p->path[i][j] == 'S'
				|| p->path[i][j] == 'E' || p->path[i][j] == 'W')
				flag++;
			j++;
		}
		i++;
	}
	if (flag != 1)
		return (free_all(p), ft_putendl_fd("Error\nincorrect", 2), 0);
	return (1);
}

int	main_parse(t_cub3d *cub, int ac, char **av)
{
	cub->map = NULL;
	cub->path = NULL;
	cub->no = NULL;
	cub->so = NULL;
	cub->we = NULL;
	cub->ea = NULL;
	cub->cieling_tmp = NULL;
	cub->floor_tmp = NULL;
	if (!file_check(ac, av) || !init_map(cub, av[1]) || \
		!check_the_valid_char(cub) || \
			!init_textures(cub) || !store_the_rgb(cub))
		return (0);
	if (!check_and_init_the_path(cub))
		return (0);
	if (!check_for_spaces(cub) || !validation(cub))
		return (0);
	put_spaces(cub->path);
	height_and_width(cub);
	if (!valid_path(cub) || !only_one_check(cub))
		return (0);
	put_walls(cub);
	return (1);
}
