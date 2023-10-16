/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:12:24 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/16 15:32:01 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void    player_moves(int btr, t_data *data)
{
    int step;
    int x_pos;
    int y_pos;

    step = 3;
    x_pos = 0;
    y_pos = 0;
    if (btr == W)
    {
        data->player.x -= cos(data->player.r_angle) * step;
        data->player.y -= sin(data->player.r_angle) * step;
        // printf("palyer_x = %d || step = %d || t_dir = %d\n", data->player.x, step, data->player.t_dir);
    }
    else if (btr == S)
    {
        data->player.x += cos(data->player.r_angle) * step;
        data->player.y += sin(data->player.r_angle) * step;
    }
    else if (btr == A)//Not work
    {
        data->player.x += cos(90 - data->player.r_angle) * step;
        data->player.y += sin(90 - data->player.r_angle) * step;
    }
    else if (btr == D)//Not work
    {
        data->player.x -= cos(90 - data->player.r_angle) * step;
        data->player.y -= sin(90 - data->player.r_angle) * step;
    }
}

void    change_view(int btr, t_data *data)
{
    if (btr == RIGHT || btr == LEFT)
    {
        if (btr == LEFT)
        {
            data->player.w_dir = -1;
            data->player.r_angle += data->player.w_dir * data->player.r_speed;
        }
        else if (btr == RIGHT)
        {
            data->player.w_dir = 1;
            data->player.r_angle += data->player.w_dir * data->player.r_speed;
        }
    }
}

int key_events(int btr, t_data *data)
{
    if (btr == LEFT || btr == RIGHT \
        || btr == W || btr == A || btr == S || btr == D)
    {
        change_view(btr, data);
        player_moves(btr, data);
        redraw(data, 1);
        draw_line(data);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
    }
    else if (btr == ESC)
		destroy_window(data);
    return (0);
}
