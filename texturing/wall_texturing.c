/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_texturing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:10:31 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/10/29 18:18:28 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void draw_line_texture(t_data *data, t_tex *tex, int top, int bottom)
{
    int     window_y;
    float   inc;
    float   tex_y;
    float   wall_height;
    float   x;
    
    wall_height = bottom - top;
    x = data->texture.current_collumn;
    tex_y = 0; 
    inc = (float)tex->height / (float)wall_height;
    window_y = top;
    int i = 0;
    while (window_y < bottom)
    {
        if(tex_y < tex->height && x < tex->width)
            get_color_texture(tex, (int)x, (int)tex_y, &data->texture.color);
        if (data->var.i >= 0 && data->var.i < WINDOW_WIDTH 
            && window_y >= 0 && window_y < WINDOW_HEIGHT)
            put_pixel(&data->img, data->var.i, window_y, data->texture.color);

         tex_y += inc;
         window_y++;
         i++;
    }
}    

void vertical_texturing(t_data *data, int top, int bottom)
{
    float tmp;
    
    tmp = data->y_wall - floor((data->y_wall / data->cub)) * data->cub;
    if (cos(data->var.angle) >= 0)
    {
        data->texture.current_collumn = (data->ea.width * tmp) / data->tile;
        draw_line_texture(data, &data->ea , top, bottom); 
    }
    else if (cos(data->var.angle) < 0)
    {
        tmp = (data->we.width * tmp) / data->tile;
        data->texture.current_collumn = data->we.width - tmp; 
        draw_line_texture(data, &data->we , top, bottom); 
    }
}

void horizontal_texturing(t_data *data, int top, int bottom)
{
    float tmp;
    
    tmp = data->x_wall - floor((data->x_wall / data->cub)) * data->cub;
    if (sin(data->var.angle) < 0)
    {
        data->texture.current_collumn = (data->no.width * tmp) / data->tile;
        draw_line_texture(data, &data->no , top, bottom);
    }
    else if (sin(data->var.angle) >= 0)
    {
        tmp = (data->so.width * tmp) / data->tile;
        data->texture.current_collumn = data->so.width - tmp; 
        draw_line_texture(data, &data->so , top, bottom);
    } 
}

void texturing(t_data *data, int top, int bottom, int state)
{

    if (state == HORIZONTAL)
        horizontal_texturing(data, top, bottom);
    if (state == VERTICAL)
        vertical_texturing(data, top, bottom);
}

void    draw_scene_line(t_data *data, int top, int bottom, int axe)
{
    int y;

    y = top;
    if (data->activate)
    {
        texturing(data, top, bottom, axe);
        //SEGV HERE!👇
        y = 0;
        while (top >= 0 && y < top && top < WINDOW_HEIGHT)
        {
            if (y >= 0 && y < WINDOW_HEIGHT)
                put_img(data->var.i, y, 0xb7d8ed, data);
            y++;
        }
        y = bottom;
        while (y >= 0 && y < WINDOW_HEIGHT && bottom < WINDOW_HEIGHT)
        {
            put_img(data->var.i, y, 0xffffff, data);
            y++;
        }
    }
}