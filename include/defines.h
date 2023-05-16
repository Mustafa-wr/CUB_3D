/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 01:52:39 by bammar            #+#    #+#             */
/*   Updated: 2023/05/16 05:17:01 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define SWIDTH 1024
# define SHEIGHT 512
# define PNAME "cub3d"
# define PI 3.141593
# define PLAYERSPEED .5
# define ROTSPEED (0.08)
# define FOV (0.78539816339) // PI / 4
# define HALF_FOV (0.392699082)
# define NUM_RAYS (SWIDTH) // 45
# define DELTA_ANGLE (FOV / NUM_RAYS) // FOV / NUM_RAYS
# define MAX_DEPTH 8

#endif