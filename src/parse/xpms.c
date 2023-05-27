/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpms.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:51:26 by mradwan           #+#    #+#             */
/*   Updated: 2023/05/27 15:59:52 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	xpm_ea(t_cub3d *cub)
{
	int	i;

	i = 0;
	if (!cub->ea || !cub->so || !cub->no || !cub->we)
		return (0);
	while (cub->ea[i])
		i++;
	i--;
	while (i > 0 && cub->ea[i] == ' ')
		i--;
	if (i > 3 && cub->ea[i] == 'm' && cub->ea[i - 1] == 'p'
		&& cub->ea[i - 2] == 'x' && cub->ea[i - 3] == '.')
		return (1);
	return (0);
}

static int	xpm_so(t_cub3d *cub)
{
	int	i;

	i = 0;
	while (cub->so[i])
		i++;
	i--;
	while (i > 0 && cub->so[i] == ' ')
		i--;
	if (i > 3 && cub->so[i] == 'm' && cub->so[i - 1] == 'p'
		&& cub->so[i - 2] == 'x' && cub->so[i - 3] == '.')
		return (1);
	return (0);
}

static int	xpm_we(t_cub3d *cub)
{
	int	i;

	i = 0;
	while (cub->we[i])
		i++;
	i--;
	while (i > 0 && cub->we[i] == ' ')
		i--;
	if (i > 3 && cub->we[i] == 'm' && cub->we[i - 1] == 'p'
		&& cub->we[i - 2] == 'x' && cub->we[i - 3] == '.')
		return (1);
	return (0);
}

static int	xpm_no(t_cub3d *cub)
{
	int	i;

	i = 0;
	while (cub->no[i])
		i++;
	i--;
	while (i > 0 && cub->no[i] == ' ')
		i--;
	if (i > 3 && cub->no[i] == 'm' && cub->no[i - 1] == 'p'
		&& cub->no[i - 2] == 'x' && cub->no[i - 3] == '.')
		return (1);
	return (0);
}

int	xpm_valid(t_cub3d *cub)
{
	if (!xpm_ea(cub) || !xpm_so(cub) || !xpm_no(cub) || !xpm_we(cub))
		return (free_all(cub),
			ft_putendl_fd("Error\nincorrect", 2), 0);
	return (1);
}
