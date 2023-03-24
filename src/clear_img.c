/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 03:02:52 by bammar            #+#    #+#             */
/*   Updated: 2023/03/25 03:04:19 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void clear_img(void *img, int width, int height)
{
    int i;
    int j;

    i = -1;
    while (++i < height)
    {
        j = -1;
        while (++j < width)
            render_pixel(img, (t_point){j, i}, 0);
    }
}
