/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 01:58:01 by mradwan           #+#    #+#             */
/*   Updated: 2023/04/05 22:06:39 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_the_path_utils(t_cub3d *p, t_vars *v)
{
	while (p->map[v->i][v->j])
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

static int	check_path_chars(t_cub3d *p)
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
				return (free_strings(p->path), free_strings(p->map), printf("Error\n"), 0);
		}
		i++;
	}
	return (1);
}

static void	init_the_path(t_cub3d *p, t_vars *v)
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
	t_vars	v;

	v.i = 0;
	v.j = 0;
	v.len = 0;
	v.tmp = 0;
	while (p->map[v.i])
	{
		v.j = 0;
		init_the_path_utils(p, &v);
		if (v.len != 0)
			break ;
		v.i++;
	}
	if (!v.len)
		return (printf("Error\n"), 0);
	init_the_path(p, &v);
	if (!check_path_chars(p))
		return (0);
	// i = 0;
	// while (p->path[i])
	// 	puts(p->path[i++]);
	return (1);
}

int	valid_path(t_cub3d *p)
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
			if (p->path[i + 1])
			{
				if (p->path[i][j] == '0')
					if (p->path[i + 1][j] == ' ')
						return (printf("Error\n"), 0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
