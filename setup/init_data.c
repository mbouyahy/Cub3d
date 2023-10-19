/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:08:47 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/19 11:26:51 by jlaazouz         ###   ########.fr       */
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
    data->width_size = WINDOW_WIDTH;//work with max_size in the code of jihad
    data->height_size = WINDOW_HEIGHT;//
    data->cub = WINDOW_WIDTH < 1000 ? 10 : 20;

    if (data->map_collums * data->cub > (WINDOW_WIDTH / 3))
        data->cub = (WINDOW_WIDTH / 3) / data->map_collums;
    if (data->map_rows * data->cub > (WINDOW_HEIGHT / 3))
        data->cub = (WINDOW_HEIGHT / 3) / data->map_rows;
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
    data->var.rotate = 0;
    data->var.move_x = 10;
    data->var.move_y = 10;
    setup_angle(data);
}
