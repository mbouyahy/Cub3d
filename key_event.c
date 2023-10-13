/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:12:24 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/13 11:45:17 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	destroy_window(t_data *data)
{
	//check leaks
    (void)data;
	exit(0);
}

void    player_moves(int btr, int step, t_data *data)
{
    if (btr == W)
    {
        data->player.x -= step;
    }
    else if (btr == A)
    {
        data->player.y -= step;
    }
    else if (btr == S)
    {
        data->player.x += step;
    }
    else if (btr == D)
    {
        data->player.y += step;
    }
}

void    change_view(int btr, t_data *data)
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
}

int key_events(int btr, t_data *data)
{
    int step;
    
    step = 5;//test
    if (btr == UP || btr == DOWN || btr == LEFT || btr == RIGHT \
        || btr == W || btr == A || btr == S || btr == D)
    {
        change_view(btr, data);
        player_moves(btr, step, data);
        redraw(data, 1);
        draw_line(data);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
    }
    else if (btr == ESC)
		destroy_window(data);
    return (0);
}
