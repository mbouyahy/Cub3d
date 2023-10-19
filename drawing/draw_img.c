/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:00:46 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/19 11:32:59 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void    init_var(t_data *data)
{
    data->var.c = 1;
    data->var.i = 0;
    data->var.x = data->player.x + data->var.move_x;
    data->var.y = data->player.y + data->var.move_y;
    data->player.x = data->var.x;
    data->player.y = data->var.y;
    data->var.x_end = 0;
    data->var.y_end = 0;
    data->var.angle = data->player.r_angle - (data->fov / 2);
    data->var.start_angle = data->player.r_angle;
    data->var.angle_inc = data->fov / data->width_size;   
}

void    draw_single_line(t_var *var, t_data *data)
{
    int     grid_x;
    int     grid_y;
    int     size;
    float   angle;

    grid_x = 0;
    grid_y = 0;
    size = data->width_size > data->height_size ? data->width_size : data->height_size;
    data->ray_length = size;

    while (var->c < data->ray_length)
    {
        angle = var->angle + var->rotate;
        var->x_end = var->x  + (var->c * cos((angle)));
        var->y_end = var->y  + (var->c * sin((angle)));
        grid_x = var->x_end / data->cub;
        grid_y = var->y_end / data->cub;
        if (data->map[grid_y][grid_x] == '1' || (data->map[grid_y][grid_x] == '0' && data->map[grid_y - 1][grid_x] == '1' \
            && data->map[grid_y][grid_x - 1] == '1' && data->map[grid_y - 1][grid_x - 1] != '1'))
            break ;
        if (var->y_end > 0 && var->x_end > 0)
            if (var->x_end < data->width_size && var->y_end < data->height_size)
                put_img(var->x_end, var->y_end, 0xFF0000, data);
        var->c++;
    }
}

void    draw_line(t_data *data)
{
    int     line_numbers;

    
    line_numbers = data->width_size;//temp
    init_var(data);
    while (data->var.i < line_numbers)
    {   
        draw_single_line(&data->var, data);
        find_distance(data, data->var.i, &data->var);
        data->var.angle += data->var.angle_inc;
        data->var.c = 1;
        data->var.i++;
    }

}
