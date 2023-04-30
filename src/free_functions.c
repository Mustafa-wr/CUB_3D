/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:49:06 by mradwan           #+#    #+#             */
/*   Updated: 2023/05/01 03:31:08 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_strings(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	if (av)
		free(av);
}

void	free_all(t_cub3d *p)
{
	free(p->cieling_tmp);
	free(p->floor_tmp);
	free(p->so);
	free(p->ea);
	free(p->no);
	free(p->we);
	free(p->floor);
	free(p->cieling);
	free_strings(p->path);
	free_strings(p->map);
}

void	free_tools(t_cub3d *p)
{
	if (p->cieling_tmp)
		free(p->cieling_tmp);
	if (p->floor_tmp)
		free(p->floor_tmp);
	if (p->so)
		free(p->so);
	if (p->ea)
		free(p->ea);
	if (p->no)
		free(p->no);
	if (p->we)
		free(p->we);
}
