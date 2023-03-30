/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:01:21 by mradwan           #+#    #+#             */
/*   Updated: 2023/03/30 18:26:41 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_nl_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

int	validation(t_cub3d *map)
{
	int	i;
	int	tmp;

	tmp = 0;
	i = 0;
	while (map->path[i])
	{
		tmp = ft_nl_strlen(map->path[i]) - 1;
		while (map->path[i][tmp] && tmp > 0)
			tmp--;
		if (map->path[i][ft_nl_strlen(map->path[i]) - 1] != '1' && \
				map->path[i][ft_nl_strlen(map->path[i]) - 1] != ' ')
			return (printf("Error\n"), 0);
		i++;
	}
	return (1);
}
