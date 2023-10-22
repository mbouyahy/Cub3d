/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:24:41 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/22 18:07:43 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	put_img1(int x, int y, unsigned int color, t_data *data)
{
	char	*pixel;

	pixel = data->img1.addr + ((y * (data->img1.line_len) + (x * (data->img1.bpp / 8))));
	*(unsigned int *)pixel = color;
}

float	distance_calc(t_data *data, t_point p)
{
	return (sqrt((p.x - data->player.x) * (p.x - data->player.x))\
				 + (p.y - data->player.y) * (p.y - data->player.y));
}

void    wall_drawing(t_data *data, float dist, int i, t_var *var)
{
    float       d_projection_plane;
    int         wall_length;
    int         top;
    int         bottom;
    float       temp_var;
    float       correct_dist;

    wall_length = 0;
    d_projection_plane = (data->width_size / 2) / tan(data->fov / 2);
    correct_dist = dist * cos(data->points.angle - data->player.r_angle);///NOT Work
    temp_var = (CUB_SIZE / correct_dist) * d_projection_plane;
    wall_length = (int)(temp_var);
    top = (data->height_size / 2) - (wall_length / 2);
    if (top < 0)
        top = 0;
    bottom = (data->height_size / 2) + (wall_length / 2);
    if (bottom > data->height_size)
        bottom = data->height_size;
    (void)var;
    (void)data;
    for (int j = top; j < bottom; j++)
    {
        if (top < data->width_size && bottom < data->height_size && i < data->width_size)
        {
            put_img(i, j, 0, data);
        }
    }
}

void    find_distance(t_data *data, float angle, int i, t_var *var)
{
    t_point         horizontal_p;
    t_point         vertical_p;
    float           vertical;
    float           horizontal;
    int             status;

    vertical = 0;
    horizontal = 0;

    horizontal_p = horizontal_intersection(data, angle);
    vertical_p = vertical_intersection(data, angle);
    horizontal = distance_calc(data, horizontal_p);
    vertical = distance_calc(data, vertical_p);
    status = 0;

    if (horizontal < vertical)
    {
        data->points.x = horizontal_p.x;
        data->points.y = horizontal_p.y;
        data->points.angle = horizontal_p.angle;
        data->points.is_vertical = horizontal_p.is_vertical;
        data->distance = horizontal;
        // wall_drawing(data, horizontal, i, var);
        status = 1;
    }
    else
    {
        data->points.x = vertical_p.x;
        data->points.y = vertical_p.y;
        data->points.angle = vertical_p.angle;
        data->points.is_vertical = horizontal_p.is_vertical;
        data->distance = vertical;
        // wall_drawing(data, vertical, i, var);
        status = 2;
    }
    (void)var;
    (void)i;
}