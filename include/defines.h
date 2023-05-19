/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 01:52:39 by bammar            #+#    #+#             */
/*   Updated: 2023/05/19 14:23:15 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define SWIDTH 1024
# define SHEIGHT 512
# define PNAME "cub3d"
# define PI 3.141593
# define PLAYERSPEED 6
# define ROTSPEED (0.05)
# define FOV (0.78539816339) // PI / 4
# define HALF_FOV (0.392699082)
# define NUM_RAYS (SWIDTH) // 45
# define DELTA_ANGLE (FOV / NUM_RAYS) // FOV / NUM_RAYS
# define SCREEN_DIST ((SWIDTH / 2.0) / tan(HALF_FOV))
# define MAX_DEPTH 8
# define IMG0_PATH ("../assets/tile000.xpm")
# define IMG1_PATH ("../assets/tile001.xpm")
# define IMG2_PATH ("../assets/tile002.xpm")
# define IMG3_PATH ("../assets/tile003.xpm")

#endif