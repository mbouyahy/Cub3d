/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:00:46 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/26 22:21:52 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void    init_var(t_data *data)
{
    data->var.c = 1;
    data->var.i = 0;
    data->var.x = data->player.x;
    data->var.y = data->player.y;
    data->var.x_end = 0;
    data->var.y_end = 0;
	data->var.angle = data->player.r_angle - (data->fov / 2);
    data->player.r_angle = remainder_angle(data->player.r_angle);
    data->var.angle_inc = data->fov / WINDOW_WIDTH;
}

void    draw_line(t_data *data)
{
    init_var(data);//for initialize the attributes
    while (data->var.i < WINDOW_WIDTH)
    {
        data->var.angle = remainder_angle(data->var.angle);//for normalize the angle
        find_distance(data);//for find the distance between the player and the wall
        drawing_wall(data);//for drawing walls
        data->var.angle += data->var.angle_inc;
        data->var.i++;
    }
}
