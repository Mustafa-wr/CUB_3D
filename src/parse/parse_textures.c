/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:03:14 by mradwan           #+#    #+#             */
/*   Updated: 2023/04/17 02:32:24 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	textures_utils(char **dst, char *src, t_vars *var, t_cub3d *t)
{
	char	*tmp;
	int		i;

	i = 0;
	while (src[i] == ' ')
		i++;
	if (src[i] == 'E' || src[i] == 'S' || src[i] == 'W' || src[i] == 'N')
		i = i + 3;
	while (src[i] != '\0' && src[i] == ' ')
		i++;
	if (src[i] != '.')
		return (ft_putendl_fd("Error", 2), free_tools(t), free_strings(t->map), exit(1), 0);
	tmp = ft_strchr(src, '.');
	(*dst) = ft_strdup(tmp);
	puts(*dst);
	var->i = -1;
	var->flag++;
	return (1);
}

static int	textures_utils2(char **dst, char *src, t_vars *var, t_cub3d *t)
{
	char	*tmp;
	int		i;

	i = 0;
	while (src[i] == ' ')
		i++;
	if (src[i] == 'F' || src[i] == 'C')
		i = i + 1;
	if (src[i] != ' ')
		return (ft_putendl_fd("Error", 2), free_strings(t->map), exit(1), 0);
	tmp = ft_strchr(src, ' ');
	var->j = 0;
	while (tmp[var->j] == ' ')
		var->j++;
	(*dst) = ft_strdup(tmp + var->j);
	puts(*dst);
	var->i = -1;
	var->flag++;
	return (1);
}

static void	init_helper(t_cub3d *t, t_vars *v)
{
	if (ft_strncmp(t->map[v->i] + v->j, "NO", 2) == 0 && v->flag == 0)
		textures_utils(&t->no, t->map[v->i], v, t);
	else if (ft_strncmp(t->map[v->i] + v->j, "SO", 2) == 0 && v->flag == 1)
		textures_utils(&t->so, t->map[v->i], v, t);
	else if (ft_strncmp(t->map[v->i] + v->j, "WE", 2) == 0 && v->flag == 2)
		textures_utils(&t->we, t->map[v->i], v, t);
	else if (ft_strncmp(t->map[v->i] + v->j, "EA", 2) == 0 && v->flag == 3)
		textures_utils(&t->ea, t->map[v->i], v, t);
	else if (ft_strncmp(t->map[v->i] + v->j, "C", 1) == 0 && v->flag == 4)
		textures_utils2(&t->ceiling_tmp, t->map[v->i], v, t);
	else if (ft_strncmp(t->map[v->i] + v->j, "F", 1) == 0 && v->flag == 5)
		textures_utils2(&t->floor_tmp, t->map[v->i], v, t);
}

static int	checker_for_t(t_cub3d *t)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (t->map[i])
	{
		j = 0;
		while (t->map[i][j])
		{
			while (t->map[i][j] == ' ')
				j++;
			if (t->map[i][j] == 'C' || t->map[i][j] == 'F')
				flag++;
			if (t->map[i][j])
				j++;
		}
		i++;
	}
	if (flag != 2)
		return (0);
	return (1);
}

int	init_textures(t_cub3d *t)
{
	t_vars	v;

	v.i = 0;
	v.flag = 0;
	v.j = 0;
	while (t->map[v.i])
	{
		v.j = 0;
		while (t->map[v.i][v.j] && (t->map[v.i][v.j] == ' '))
			v.j++;
		if (v.flag == 6)
			break ;
		init_helper(t, &v);
		v.i++;
	}
	if (v.flag != 6 || !checker_for_t(t))
		return (ft_putendl_fd("Error", 2), free_strings(t->map), 0);
	return (1);
}
