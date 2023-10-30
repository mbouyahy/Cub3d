/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:53:41 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/29 18:32:48 by mbouyahy         ###   ########.fr       */
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
    data->minimap.x = (data->player.x / data->cub) * data->cub;
    data->minimap.y = (data->player.y / data->cub) * data->cub;
    
    var->x = data->player.x;
    var->y = data->player.y;
    data->player.x = data->minimap.x;
    data->player.y = data->minimap.y;

    data->var.height = data->window_height;
    data->var.width = data->window_width;
    data->window_height = data->minimap.height;
    data->window_width = data->minimap.width;
    
	data->var.angle = data->player.r_angle - (data->fov / 2);
    var->angle_inc = data->fov / data->minimap.width;
}

//for testing
void dda_draw(t_data *data, float  X0, float Y0, float X1, float Y1) 
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
    for (int i = 0; i < steps; i++)
	{
		if (X >= data->minimap.width || Y >= data->minimap.height)
			break;
        // if (status == 1)
            // put_img(X, Y, 257468, data); // put pixel at (X,Y)
        // else
            put_img(X, Y, 0xFF0000, data); // put pixel at (X,Y)
        X += x_; // increment in x at each step 
        Y += y_; // increment in y at each step 
                    // generation step by step 
    } 
}

void    draw_single_line(t_data *data)
{
    if (data->type == HORIZONTAL)
        dda_draw(data, data->player.x, data->player.y , data->Horiz.x, data->Horiz.y);//testing
    else if (data->type == VERTICAL)
        dda_draw(data, data->player.x, data->player.y , data->Vert.x, data->Vert.y);//testing
}

void    draw_minimap(t_data *data)
{
    t_var var;

    draw_map(data);
    init_var_(data, &var);//for initialize the attributes
    data->activate = 0;
    while (var.i < data->minimap.width)
    {
        data->var.angle = remainder_angle(data->var.angle);//for normalize the angle
        find_distance(data);//for find the distance between the player and the wall
        draw_single_line(data);//for drawing rays
        data->var.angle += var.angle_inc;
        var.i++;
    }
    data->player.x = var.x;
    data->player.y = var.y;
    data->window_height = data->var.height;
    data->window_width = data->var.width;
}
