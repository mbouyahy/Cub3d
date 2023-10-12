/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:12:24 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/12 19:55:31 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cup3d.h"

int	destroy_window(t_data *data)
{
	//check leaks
    (void)data;
	exit(0);
}

int player_moves(int btr, t_data *data)
{
    int step;
    
    step = 50;//test
    if (btr == UP || btr == DOWN || btr == LEFT || btr == RIGHT)
    {
        if (btr == UP)
        {
            data->player.t_dir = -1;
            data->player.r_angle += data->player.t_dir * data->player.r_speed;
            // step = 1 * data->player.m_speed;
            // printf("%d\n", step);
            // data->player.x = cos(data->player.r_angle) * step;
            // data->player.y = sin(data->player.r_angle) * step;
            // if (data->player.y < data->width_size && data->player.y > 0)
            data->player.x += step;//test
        }
        else if (btr == DOWN)
        {
            data->player.t_dir = 1;
            data->player.r_angle += data->player.t_dir * data->player.r_speed;
            data->player.x -= step;//test
        }
        else if (btr == LEFT)
        {
            data->player.w_dir = 1;
            data->player.r_angle += data->player.w_dir * data->player.r_speed;
            data->player.y -= step;//test
        }
        else if (btr == RIGHT)
        {
            data->player.w_dir = -1;
            data->player.r_angle += data->player.w_dir * data->player.r_speed;
            data->player.y += step;//test
        }
        redraw(data, 1);
        draw_line(data);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
    }
    else if (btr == ESC)
		destroy_window(data);
    return (0);
}
