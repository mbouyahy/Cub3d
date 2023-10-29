/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:24:41 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/29 15:12:16 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

float    abs_angle(t_data *data)
{
    if (data->var.angle > data->player.r_angle)
        return (data->var.angle - data->player.r_angle);
    else if (data->var.angle < data->player.r_angle)
        return (data->player.r_angle - data->var.angle);
    return (data->var.angle);
}

void    drawing_wall(t_data *data, int axe)
{
    float	correct_distance;
    float	projectionWallH;
    int		top;
    int		bottom;
    
    correct_distance = data->distance * cos(abs_angle(data));
    projectionWallH = (data->tile / correct_distance) * (WINDOW_WIDTH / 2) / tanf((data->fov / 2));
    top = (WINDOW_HEIGHT - (int)projectionWallH) / 2;
    bottom = top + projectionWallH;

    draw_scene_line(data, top, bottom, axe);
}

float	distance_calc(t_data *data, int value)
{
    if (value == HORIZONTAL)
    {
        return (sqrt(((data->player.x - data->Horiz.x) * ( data->player.x - data->Horiz.x))\
                    + ((data->player.y - data->Horiz.y) * (data->player.y - data->Horiz.y))));
    }
    else if (value == VERTICAL)
    {
        return (sqrt(((data->player.x - data->Vert.x) * ( data->player.x - data->Vert.x))\
            + ((data->player.y - data->Vert.y) * (data->player.y - data->Vert.y))));
    }
    return (0);
}

void wall(t_data *data, float hor, float ver)
{
    if (hor < ver)
    {
        data->distance = hor;
        data->x_wall = data->Horiz.x;
        data->y_wall = data->Horiz.y;
        drawing_wall(data, HORIZONTAL);
    }
    else
    {
        data->distance = ver;
        data->x_wall = data->Vert.x;
        data->y_wall = data->Vert.y;
        drawing_wall(data, VERTICAL);
    }  
}

void    find_distance(t_data *data)
{
    float           vertical;
    float           horizontal;

    vertical = 0;
    horizontal = 0;

    horizontal_intersection(data);
    vertical_intersection(data);
    if (data->Horiz.iswall)
        horizontal = distance_calc(data, HORIZONTAL);
    else
        horizontal = MAX_I;
    if (data->Vert.iswall)
        vertical = distance_calc(data, VERTICAL);
    else
        vertical = MAX_I;
    wall(data, horizontal, vertical);
}
