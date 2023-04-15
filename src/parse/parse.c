/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:27:29 by mradwan           #+#    #+#             */
/*   Updated: 2023/04/12 19:47:36 by mradwan          ###   ########.fr       */
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
				return (free_strings(check->map), printf("Error\n"), 0);
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

	i = 0;
	j = 0;
	int flag = 0;
	while (p->path[i])
	{
		j = 0;
		while (p->path[i][j])
		{
			if (p->path[i][j] == 'N' || p->path[i][j] == 'S' || p->path[i][j] == 'E' || p->path[i][j] == 'W')
				flag++;
			j++;
		}
		i++;
	}
	if (flag != 1)
		return (free_all(p), printf("Error\n"), 0);
	return (1);
}

int	main_parse(t_cub3d *cub, int ac, char **av)
{
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
	// int i = 0;
	// while (cub->path[i])
	// {
	// 	printf("{%s}\n",(cub->path[i++]));
	// 	fflush(stdout);
	// }
	// printf("hi\n");
	return (1);
}

// int	main(int ac, char **av)
// {
// 	t_cub3d	cub;
	
// 	// if(!file_check(ac, av) || !init_map(&cub, av[1]) || !init_textures(&cub) || !store_the_rpg(&cub) || !check_the_valid_char(&cub))
// 	// 	return (0);
// 	// if(!check_and_init_the_path(&cub))
// 	// 	return 0;
// 	if (!main_parse(&cub, ac, av))
// 		return (0);
// }
