/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:00:46 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/16 10:57:46 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void    init_var(t_var *var, t_data *data)
{
    var->c = 1;
    var->i = 0;
    var->x = data->player.x;
    var->y = data->player.y;
    var->x_end = 0;
    var->y_end = 0;
    var->angle = data->player.r_angle - (data->fov / 2);
    var->angle_inc = data->fov / data->width_size;
}

void    draw_line(t_data *data)
{
    t_var	var;
    int     grid_x;
    int     grid_y;

    init_var(&var, data);
    grid_x = 0;
    grid_y = 0;
    while (var.i < data->width_size)
    {
        while (var.c < data->ray_length)
        {   
            var.x_end = var.x - (var.c * cos(var.angle));
            var.y_end = var.y - (var.c * sin(var.angle));
            grid_x = var.x_end / data->cub;
            grid_y = var.y_end / data->cub;
            if (data->map[grid_y][grid_x] == '1')
                break ;
            if (var.y_end > 0 && var.x_end > 0)
            {
                if (var.x_end < data->width_size && var.y_end < data->height_size)
                    put_img(var.x_end, var.y_end, 0xFF0000, data);
            }
            var.c++;
        }
        var.angle += var.angle_inc;
        var.c = 1;
        var.i++;
    }
}
