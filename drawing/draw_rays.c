/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:00:46 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/29 14:59:12 by jlaazouz         ###   ########.fr       */
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
    data->x_ = 0;
    while (data->var.i < WINDOW_WIDTH)
    {
        data->var.angle = remainder_angle(data->var.angle);//for normalize the angle
        find_distance(data);//for find the distance between the player and the wall
        data->var.angle += data->var.angle_inc;
        data->var.i++;
    }
}
