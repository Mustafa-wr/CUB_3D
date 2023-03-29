/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:27:29 by mradwan           #+#    #+#             */
/*   Updated: 2023/03/30 02:16:35 by mradwan          ###   ########.fr       */
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
	return (1);
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
