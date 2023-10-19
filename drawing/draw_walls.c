/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:24:41 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/19 11:33:50 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void    drawline_(t_data *data, t_var *var, int x_start, int x_end, int y_end, int i)
{
    // t_var var;

    var->c = i;
    while (x_start < y_end)
    {   
        var->x_end = x_end - (var->c * cos(var->angle + var->rotate));
        var->y_end = y_end - (var->c * sin(var->angle + var->rotate));
        if (y_end > 0 && x_end > 0)
        {
            // printf("DONE\n");
            if (x_end < data->width_size && y_end < data->height_size)
                put_img(x_start, y_end, 0xFF0000, data);
        }
        var->c++;
        x_start++;
    }
}

void    walldraw_(t_data *data, int dist, int i, t_var *var)
{
    float       d_projection_plane;
    int         wall_length;
    int         top;
    int         bottom;

    d_projection_plane = (data->width_size / 2) / tan(( 60 * (M_PI / 180) ) / 2);
    wall_length = 0;
    bottom = data->height_size;
    if (dist > 0)
    {
        wall_length = (data->cub / dist) * d_projection_plane;
        printf("wall_length = %d\n", wall_length);
    }
    top = (data->height_size / 2) - (wall_length / 2);
    if (top < 0)
        top = 0;
    bottom = (data->height_size / 2) + (wall_length / 2);
    if (bottom > data->height_size)
        bottom = data->height_size;
    // (void)i;
    drawline_(data, var, i, top, bottom, i);//problem
}

void    find_distance(t_data *data, int i, t_var *var)
{
    int     vertical;
    int     horizontal;

    vertical = horizontal_intersection(data);
    horizontal = vertical_intersection(data);
    if (vertical < horizontal && vertical > 0)
    {
        printf("vertical %d : DONE\n", vertical);
        walldraw_(data, vertical, i, var);
    }
    else if (vertical > horizontal && horizontal > 0)
    {
        printf("horizontal %d : DONE\n", horizontal);
        walldraw_(data, horizontal, i, var);
    }
}