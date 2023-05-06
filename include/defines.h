/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bammar <bammar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 01:52:39 by bammar            #+#    #+#             */
/*   Updated: 2023/05/06 17:11:38 by bammar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define SWIDTH 1000
# define SHEIGHT 1000
# define PNAME "cub3d"
# define PI 3.141593
# define PLAYERSPEED 0.1
# define ROTSPEED 5.0
# define FOV (PI / 3.0)
# define NUM_RAYS (SWIDTH / 2)
# define DELTA_ANGLE (FOV / NUM_RAYS)
# define SCALE (SWIDTH / NUM_RAYS)

#endif