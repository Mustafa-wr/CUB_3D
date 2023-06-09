/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_spaces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:18:54 by mradwan           #+#    #+#             */
/*   Updated: 2023/05/25 20:40:49 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	largest_string_length(char **arr)
{
	int	i;
	int	max_len;
	int	len;

	i = 0;
	max_len = 0;
	len = 0;
	while (arr[i])
	{
		len = ft_strlen(arr[i]);
		if (len > max_len)
			max_len = len;
		i++;
	}
	return (max_len);
}

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	put_spaces(char **arr)
{
	int		i;
	int		j;
	int		len;
	t_vars	v;

	i = 0;
	v.max_len = largest_string_length(arr);
	while (arr[i])
	{
		len = ft_strlen(arr[i]);
		v.num_spaces = v.max_len - len;
		v.new_str = malloc((v.max_len + 1) * sizeof(char));
		ft_strcpy(v.new_str, arr[i]);
		j = -1;
		while (++j < v.num_spaces)
			v.new_str[len + j] = ' ';
		v.new_str[v.max_len] = '\0';
		free(arr[i]);
		arr[i] = v.new_str;
		i++;
	}
}

void	put_walls(t_cub3d *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cub->path[i])
	{
		j = 0;
		while (cub->path[i][j])
		{
			if (cub->path[i][j] == ' ')
				cub->path[i][j] = '2';
			j++;
		}
		i++;
	}
}

int	xpm_check(t_cub3d *cub)
{
	int	fd;

	fd = open(cub->no, O_RDONLY);
	if (fd < 0)
		return (free_all(cub), ft_putendl_fd("Error\nincorrect", 2), 0);
	close(fd);
	fd = open(cub->ea, O_RDONLY);
	if (fd < 0)
		return (free_all(cub), ft_putendl_fd("Error\nincorrect", 2), 0);
	close(fd);
	fd = open(cub->we, O_RDONLY);
	if (fd < 0)
		return (free_all(cub), ft_putendl_fd("Error\nincorrect", 2), 0);
	close(fd);
	fd = open(cub->so, O_RDONLY);
	if (fd < 0)
		return (free_all(cub), ft_putendl_fd("Error\nincorrect", 2), 0);
	close(fd);
	return (1);
}
