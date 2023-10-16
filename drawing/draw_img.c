/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:00:46 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/16 15:31:35 by mbouyahy         ###   ########.fr       */
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

void    draw_single_line(t_var *var, t_data *data)
{
    int     grid_x;
    int     grid_y;
    int     size;

    grid_x = 0;
    grid_y = 0;
    size = data->width_size > data->height_size ? data->width_size : data->height_size;
    data->ray_length = size - var->x;
    while (var->c < data->ray_length)
    {   
        var->x_end = var->x - (var->c * cos(var->angle));
        var->y_end = var->y - (var->c * sin(var->angle));
        grid_x = var->x_end / data->cub;
        grid_y = var->y_end / data->cub;
        if (data->map[grid_y][grid_x] == '1')
            break ;
        if (var->y_end > 0 && var->x_end > 0)
        {
            if (var->x_end < data->width_size && var->y_end < data->height_size)
                put_img(var->x_end, var->y_end, 0xFF0000, data);
        }
        var->c++;
    }
}

void    draw_line(t_data *data)
{
    t_var	var;
    int     line_numbers;

    
    line_numbers = data->width_size;//temp
    init_var(&var, data);
    while (var.i < line_numbers)
    {
        draw_single_line(&var, data);
        // find_distance(data, var.i, &var);
        var.angle += var.angle_inc;
        var.c = 1;
        var.i++;
    }
}
