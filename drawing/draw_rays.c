/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:00:46 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/22 18:15:04 by mbouyahy         ###   ########.fr       */
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
    data->var.start_angle = data->player.r_angle;
    data->var.angle = data->player.r_angle - (data->fov / 2);
    data->var.angle_inc = data->fov / data->width_size;
}

void draw_line_(t_data *data, double x1, double y1, double x2, double y2)
{
    double dx = x2 - x1;
    double dy = y2 - y1;
    double steps = fmax(fabs(dx), fabs(dy));
    double xIncrement = dx / steps;
    double yIncrement = dy / steps;
    double x = x1, y = y1;

    int     grid_x;
    int     grid_y;

    for (int i = 0; i <= steps; i++)
    {
        grid_x = (int)floor(x / data->cub);
        grid_y = (int)floor(y / data->cub);
        if (data->map[grid_y][grid_x] == '1' || (data->map[grid_y][grid_x] == '0' && data->map[grid_y - 1][grid_x] == '1' \
            && data->map[grid_y][grid_x - 1] == '1' && data->map[grid_y - 1][grid_x - 1] != '1'))
            break ;
        if (x < data->width_size && y < data->height_size)
            put_img(x, y, 4524654, data); // Set the pixel at (x, y) to white
        x += xIncrement;
        y += yIncrement;
    }
}

void    draw_single_line(t_var *var, t_data *data)
{
    // size_t  grid_x;
    // size_t  grid_y;
    // int     size;
    // float   angle;

    // // grid_x = 0;
    // // grid_y = 0;
    // size = data->width_size > data->height_size ? data->width_size : data->height_size;
    // data->ray_length = size;
    // while (var->c < data->ray_length)
    // {
    //     // angle = var->angle + var->rotate;
    //     angle = data->player.r_angle - (30 * (M_PI / 180));
    //     // var->x_end = var->x + (var->c * cos((angle)));
    //     // var->y_end = var->y + (var->c * sin((angle)));
    //     // grid_x = var->x_end / data->cub;
    //     // grid_y = var->y_end / data->cub;
    //     // if ((data->map[grid_y][grid_x] == '1'
    //     //      || (data->map[grid_y][grid_x] == '0' && data->map[grid_y - 1][grid_x] == '1' 
    //     //     && data->map[grid_y][grid_x - 1] == '1' && data->map[grid_y - 1][grid_x - 1] != '1')))
    //     //     break ;
    //     // if (var->y_end > 0 && var->x_end > 0)
    //     // {
    //     //     if (var->x_end < data->width_size && var->y_end < data->height_size)
    //     //         put_img(var->x_end, var->y_end, 0xFF0000, data);
    //     // }
    //     var->c++;
    // }
    // data->points.angle = angle;
    // exit(0);
    (void)var;
    (void)data;
    draw_line_(data, data->player.x, data->player.y , data->points.x, data->points.y);//testing
}

void    drawing_wall(t_data *data, float angle)//for testing
{
    (void)angle;
    float distanceprojection = (data->width_size / 2) / tan(data->fov / 2);
    float projectionWallH = (CUB_SIZE / data->distance) * distanceprojection;

    int wallStripH = (int)projectionWallH;

    int wallTP = (data->height_size / 2) - (wallStripH / 2);
    wallTP = wallTP < 0 ? 0 : wallTP;

    int wallBP = (data->height_size / 2) + (wallStripH / 2);
    wallBP = wallBP > data->height_size ? data->height_size : wallBP;

    for (int y = wallTP; y < wallBP; y++)
    {
        put_img(data->var.i, y, 3456, data);
    }
}

void    draw_line(t_data *data)
{
    init_var(data);
    float temp_An = data->var.angle_inc;
    while (temp_An < data->fov)
    {
        find_distance(data, data->var.angle, data->var.i, &data->var);
        draw_single_line(&data->var, data);
        drawing_wall(data, data->var.angle);
        data->var.angle += data->var.angle_inc;
        temp_An += data->var.angle_inc;//for testing only 
        data->var.c = 1;
        data->var.i++;
    }
}
