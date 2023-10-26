/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:24:41 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/26 22:00:33 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void    draw_special_line(t_data *data, int top, int bottom)
{
    int y;

    y = top;
    while (y < bottom)
    {
        put_img(data->var.i, y, 3456, data);
        y++;
    }
    //SEGV HERE!👇
    y = 0;
    while (top > 0 && y < top && top < WINDOW_HEIGHT)
    {
        if (y > 0 && y < WINDOW_HEIGHT)
            put_img(data->var.i, y, 0xb7d8ed, data);
        y++;
    }
    y = bottom;
    while (y > 0 && y < WINDOW_HEIGHT && bottom < WINDOW_HEIGHT)
    {
        put_img(data->var.i, y, 0xffffff, data);
        y++;
    }
}

float    abs_angle(t_data *data)
{
    if (data->var.angle > data->player.r_angle)
        return (data->var.angle - data->player.r_angle);
    else if (data->var.angle < data->player.r_angle)
        return (data->player.r_angle - data->var.angle);
    return (data->var.angle);
}

void    drawing_wall(t_data *data)
{
    float	correct_distance;
    float	projectionWallH;
    int		top;
    int		bottom;
    
    correct_distance = data->distance * cos(abs_angle(data));
    projectionWallH = (CUB_SIZE / correct_distance) * (WINDOW_WIDTH / 2) / tanf((data->fov / 2));
    top = (WINDOW_HEIGHT / 2) - ((int)projectionWallH / 2);
    if (top < 0)
        top = 0;
    bottom = (WINDOW_HEIGHT / 2) + ((int)projectionWallH / 2);
    if (bottom > WINDOW_HEIGHT)
        bottom = WINDOW_HEIGHT;
    draw_special_line(data, top, bottom);
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
    if (horizontal < vertical)
        data->distance = horizontal;
    else
        data->distance = vertical;
}