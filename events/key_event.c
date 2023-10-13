/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:12:24 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/13 21:42:10 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	destroy_window(t_data *data)
{
	//check leaks
    (void)data;
	exit(0);
}

float   deg_to_rad(int deg)
{
    return (deg * (M_PI / 180));   
}

float   deg_cos(int deg)
{
    return (deg_to_rad(deg));
}

float   deg_sin(int deg)
{
    return (deg_to_rad(deg));
}

void    player_moves(int btr, t_data *data)
{
    int step;
    int x_pos;
    int y_pos;
    
    // step = 5;
    step = 0;
    x_pos = 0;
    y_pos = 0;
    if (btr == W)
    {
        // data->player.x -= step;
        step = 0.1 * data->player.m_speed;
        data->player.x -= cos(data->player.r_angle) * step;
        data->player.y -= sin(data->player.r_angle) * step;
        // printf("palyer_x = %d || step = %d || t_dir = %d\n", data->player.x, step, data->player.t_dir);
    }
    else if (btr == S)
    {
        // data->player.x += step;
        step = 0.1 * data->player.m_speed;
        data->player.x += cos(data->player.r_angle) * step;
        data->player.y += sin(data->player.r_angle) * step;
    }
    else if (btr == A)
    {
        // step = 0.1 * data->player.m_speed;
        data->player.y--;
        // data->player.x += deg_cos(90);
        // data->player.y += deg_sin(90);
    }
    else if (btr == D)
    {
        // step = 0.1 * data->player.m_speed;
        data->player.y++;
        // data->player.x -= deg_cos(90);
        // data->player.y -= deg_sin(90);
    }
}

void    change_view(int btr, t_data *data)
{
    //  if (btr == UP)
    //     {
    //         data->player.t_dir = -1;
    //         data->player.r_angle += data->player.t_dir * data->player.r_speed;
    //     }
    //     else if (btr == DOWN)
    //     {
    //         data->player.t_dir = 1;
    //         data->player.r_angle += data->player.t_dir * data->player.r_speed;
    //     }
    //     else 
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

int key_events(int btr, t_data *data)
{
    if (btr == UP || btr == DOWN || btr == LEFT || btr == RIGHT \
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
