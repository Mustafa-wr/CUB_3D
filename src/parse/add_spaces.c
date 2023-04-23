/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_spaces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:18:54 by mradwan           #+#    #+#             */
/*   Updated: 2023/04/23 19:59:57 by mradwan          ###   ########.fr       */
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
		ft_strlcpy(v.new_str, arr[i], ft_strlen(arr[i]));
		j = -1;
		while (++j < v.num_spaces)
			v.new_str[len + j] = ' ';
		v.new_str[v.max_len] = '\0';
		free(arr[i]);
		arr[i] = v.new_str;
		i++;
	}
}
