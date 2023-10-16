/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:12:24 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/16 17:55:47 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void    player_moves(int btr, t_data *data)
{
    int step;
    int grid_x;
    int grid_y;

    step = 3;//temp
    if (btr == W)
    {
		grid_x = (data->player.x - cos(data->player.r_angle) * step) / data->cub;
    	grid_y = (data->player.y - sin(data->player.r_angle) * step) / data->cub;
		if (data->map[grid_y][grid_x] == '0' ||  ft_strchr(MAP_DIRECTIONS, data->map[grid_y][grid_x]))
        {
			data->player.x -= cos(data->player.r_angle) * step;
			data->player.y -= sin(data->player.r_angle) * step;
		}
    }
    else if (btr == S)
    {
		grid_x = (data->player.x + cos(data->player.r_angle) * step) / data->cub;
    	grid_y = (data->player.y + sin(data->player.r_angle) * step) / data->cub;
		if (data->map[grid_y][grid_x] == '0' || ft_strchr(MAP_DIRECTIONS, data->map[grid_y][grid_x]))
        {
			data->player.x += cos(data->player.r_angle) * step;
			data->player.y += sin(data->player.r_angle) * step;
		}
    }
    else if (btr == A)//Not work yet
    {
		grid_x = (data->player.x + cos(90 - data->player.r_angle) * step) / data->cub;
    	grid_y = (data->player.y + sin(90 - data->player.r_angle) * step) / data->cub;
		if (data->map[grid_y][grid_x] == '0' || ft_strchr(MAP_DIRECTIONS, data->map[grid_y][grid_x]))
        {
			data->player.x += cos(90 - data->player.r_angle) * step;
			data->player.y += sin(90 - data->player.r_angle) * step;
		}
    }
    else if (btr == D)//Not work yet
    {
		grid_x = (data->player.x - cos(90 - data->player.r_angle) * step) / data->cub;
    	grid_y = (data->player.y - sin(90 - data->player.r_angle) * step) / data->cub;
		if (data->map[grid_y][grid_x] == '0' || ft_strchr(MAP_DIRECTIONS, data->map[grid_y][grid_x]))
        {
			data->player.x -= cos(90 - data->player.r_angle) * step;
			data->player.y -= sin(90 - data->player.r_angle) * step;
		}
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
