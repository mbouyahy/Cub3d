/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:08:47 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/22 18:09:21 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ft_init(t_data *cub)
{
	cub->file = NULL;
	cub->file_len = 0;
	cub->map_rows  = 0;
	cub->map_start = 0;
	cub->visuals_len = 0;
	cub->file_len = 0;
	cub->map_collums  = 0;
	cub->map_grid = NULL;
	cub->visual_data = NULL;
	cub->visuals = (t_visuals *)ft_calloc(1, sizeof(t_visuals));
}

void    init_data(t_data  *data)
{

    //data init
    data->map = data->map_grid;
    data->map_size = data->map_rows;
    data->x_start = 0;
    data->y_start = 0;
    data->cub = 40;
    data->inside = 0;
    data->fov = 60 * (M_PI / 180);
    data->height_size = data->map_rows * data->cub;
    data->width_size = data->map_collums * (data->cub - 2);

    // if (data->map_collums * data->cub > (WINDOW_WIDTH / 3))
    //     data->cub = (WINDOW_WIDTH / 3) / data->map_collums;
    // if (data->map_rows * data->cub > (WINDOW_HEIGHT / 3))
    //     data->cub = (WINDOW_HEIGHT / 3) / data->map_rows;
    
    //player init
    // data->player.y = data->player.y * CUB_SIZE + (CUB_SIZE / 2);
    // data->player.x = data->player.x * CUB_SIZE + (CUB_SIZE / 2);
    data->player.rad = 3;
    data->player.w_dir = 0;
    data->player.t_dir = 0;
    data->player.r_speed = 2 * (M_PI / 180);
    data->player.m_speed = 50;
    data->player.p_direction = '\0';
    data->var.rotate = 0;
    data->var.move_x = 0;
    data->var.move_y = 0;
    setup_angle(data);
}
