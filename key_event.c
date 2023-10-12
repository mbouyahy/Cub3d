/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:12:24 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/12 19:12:54 by mbouyahy         ###   ########.fr       */
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
    float step;
    
    step = 0.0;
    if (btr == UP || btr == DOWN || btr == LEFT || btr == RIGHT)
    {
        if (btr == UP)
        {
            data->player.t_dir = -1;
            data->player.r_angle += data->player.t_dir * data->player.r_speed;
        }
        else if (btr == DOWN)
        {
            data->player.t_dir = 1;
            data->player.r_angle += data->player.t_dir * data->player.r_speed;
        }
        else if (btr == LEFT)
        {
            data->player.w_dir = 1;
            data->player.r_angle += data->player.w_dir * data->player.r_speed;
        }
        else if (btr == RIGHT)
        {
            data->player.w_dir = -1;
            data->player.r_angle += data->player.w_dir * data->player.r_speed;
        }
        redraw(data);
        draw_line(data);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
    }
    else if (btr == ESC)
		destroy_window(data);
    return (0);
}
