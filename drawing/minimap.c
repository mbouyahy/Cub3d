/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:53:41 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/27 11:18:29 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void draw_square(t_data *data, int color, int cub)
{
    int i = 0;
    int j = 0;

    data->x_start *= cub;
    data->y_start *= cub;
    while (j <= cub)
    {
        while (i <= cub)
        {
            if (data->x_start + i < data->minimap.width \
				&& data->y_start + j < data->minimap.height)
                put_img(data->x_start + i, data->y_start + j, color, data);
            i++;
        }
        i = 0;
        j++;
    }
}

void    draw_map(t_data *data)
{
    int     x;
    int     y;

    x = -1;
    y = -1;

    while (++y < data->map_size)
    {
        while (data->map[y][++x])
        {
			data->x_start = x;
			data->y_start = y;
            if (data->map[y][x] == '1')
            {
                draw_square(data, 0xffffff, data->cub);
            }
            else if (data->map[y][x] == '0' || ft_strchr(MAP_DIRECTIONS, data->map[y][x]))
                draw_square(data, 4868967, data->cub);
        }
        x = -1;
    }
}

void    init_var_(t_data *data, t_var *var)
{
    var->c = 1;
    var->i = 0;
    data->minimap.x = (data->player.x / data->cub);
    data->minimap.y = (data->player.y / data->cub);
    data->minimap.x = data->minimap.x * data->cub;
    data->minimap.y = data->minimap.y * data->cub;
    var->x = data->minimap.x;
    var->y = data->minimap.y;
	var->angle = data->player.r_angle - (data->fov / 2);
    var->angle_inc = data->fov / data->minimap.width;
}

void    draw_single_line(t_var *var, t_data *data)
{
    size_t  grid_x;
    size_t  grid_y;
    float   x_end;
    float   y_end;

    grid_x = 0;
    grid_y = 0;
    data->minimap.ray_length = data->minimap.width;
    while (var->c < data->minimap.ray_length)
    {
        x_end = var->x + (var->c * cos((var->angle)));
        y_end = var->y + (var->c * sin((var->angle)));
        grid_x = (int)(x_end / data->cub);
        grid_y = (int)(y_end / data->cub);
        if (y_end >= 0 && x_end >= 0 && x_end <= data->minimap.width && y_end <= data->minimap.height)
        {
            if (data->map[grid_y][grid_x] == '0' || ft_strchr(MAP_DIRECTIONS, data->map[grid_y][grid_x]))
                put_img(x_end, y_end, 0xFF0000, data);
            else
                break ;
        }
        var->c++;
    }
}

void    draw_minimap(t_data *data)
{
    t_var var;

    draw_map(data);
    init_var_(data, &var);//for initialize the attributes
    while (var.i < data->minimap.width)
    {
        var.angle = remainder_angle(var.angle);//for normalize the angle
        draw_single_line(&var, data);//for drawing rays
        var.angle += var.angle_inc;
        var.c = 1;
        var.i++;
    }
}
