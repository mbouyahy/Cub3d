/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:08:47 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/15 19:29:05 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void    init_data(t_data  *data)
{
    //player init
    data->player.x = 0;
    data->player.y = 0;
    data->player.rad = 3;
    data->player.w_dir = 0;
    data->player.r_angle = M_PI / 2;
    data->player.r_speed = 3 * (M_PI / 180);
    data->player.m_speed = 50;
    data->player.p_direction = '\0';

    //data init
    data->map = data->map_grid;
    data->map_size = data->map_rows;
    data->x_start = 0;
    data->y_start = 0;
    data->cub = 60;
    data->ray_length = 200;
    data->fov = 60 * (M_PI - 180);
    data->width_size = (data->map_collums - 1) * data->cub;//work with max_size in the code of jihad
    data->height_size = data->map_rows * data->cub;
}
