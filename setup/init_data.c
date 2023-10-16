/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:08:47 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/16 20:22:59 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void    init_data(t_data  *data)
{

    //data init
    data->map = data->map_grid;
    data->map_size = data->map_rows;
    data->x_start = 0;
    data->y_start = 0;
    //dynamic cub => 
    // data->cub = 20;
    data->inside = 0;
    data->fov = 60 * (M_PI / 180);
    data->width_size = WINDOW_WIDTH / 3;//work with max_size in the code of jihad
    data->height_size = WINDOW_HEIGHT / 3;//
    data->cub = WINDOW_WIDTH < 1000 ? 10 : 20;
    // data->width_size = (data->map_collums - 1) * data->cub;//work with max_size in the code of jihad
    // data->height_size = data->map_rows * data->cub;
    
    //player init
    // data->player.x = 0;
    // data->player.y = 0;
    data->player.y = data->player.y * data->cub + (data->cub / 2);
    data->player.x = data->player.x * data->cub + (data->cub / 2);
    data->player.rad = 3;
    data->player.w_dir = 0;
    data->player.r_angle = M_PI / 2;
    data->player.r_speed = 10 * (M_PI / 180);
    data->player.m_speed = 50;
    data->player.p_direction = '\0';
}
