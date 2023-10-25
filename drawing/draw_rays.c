/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:00:46 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/25 20:08:44 by mbouyahy         ###   ########.fr       */
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
    data->player.r_angle = remainder_angle(data->player.r_angle);
    data->var.angle_inc = data->fov / data->width_size;
}

//for testing
void dda_draw(t_data *data, float  X0, float Y0, float X1, float Y1, int status) 
{ 
    // calculate dx & dy 
    float dx = X1 - X0; 
    float dy = Y1 - Y0; 
  
    // calculate steps required for generating pixels 
    float steps = fabsf(dx) > fabsf(dy) ? fabsf(dx) : fabsf(dy); 
  
    // calculate increment in x & y for each steps 
    float x_ = dx / (float)steps; 
    float y_ = dy / (float)steps; 
  
    // Put pixel for each step 
    float X = X0; 
    float Y = Y0; 
    for (int i = 0; i <= steps; i++)
	{
		if (X >= data->width_size || Y >= data->height_size)
			break;
        if (status == 1)
            put_img(X, Y, 257468, data); // put pixel at (X,Y)
        else
            put_img(X, Y, 2454, data); // put pixel at (X,Y)
        X += x_; // increment in x at each step 
        Y += y_; // increment in y at each step 
                    // generation step by step 
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
    if (data->type == HORIZONTAL)
        dda_draw(data, data->player.x, data->player.y , data->Horiz.x, data->Horiz.y, 1);//testing
    else if (data->type == VERTICAL)
        dda_draw(data, data->player.x, data->player.y , data->Vert.x, data->Vert.y, 1);//testing
}

void    draw_line(t_data *data)
{
    init_var(data);//for initialize the attributes
    while (data->var.i < data->width_size)
    {
        data->var.angle = remainder_angle(data->var.angle);//for normalize the angle
        find_distance(data);//for find the distance between the player and the wall
        draw_single_line(&data->var, data);//for drawing rays
        drawing_wall(data);//for drawing walls
        data->var.angle += data->var.angle_inc;
        // data->var.c = 1;//i need this
        data->var.i++;
    }
}
