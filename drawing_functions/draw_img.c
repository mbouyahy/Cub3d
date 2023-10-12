/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:00:46 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/12 19:10:49 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cup3d.h"

void	put_img(int x, int y, unsigned int color, t_data *data)
{
	char	*pixel;

	pixel = data->img.addr + ((y * (data->img.line_len) + (x * (data->img.bpp / 8))));
	*(unsigned int *)pixel = color;
}

void draw_square(t_data *data, int color, int cup)
{
    int i = 0;
    int j = 0;

    data->x_start *= cup;
    data->y_start *= cup;
    while (j < cup)
    {
        while (i < cup)
        {
            if (data->x_start + i < data->width_size && data->y_start + j < data->height_size)
                put_img(data->x_start + i, data->y_start + j, color, data);
            i++;
        }
        i = 0;
        j++;
    }
}

void    draw_map(t_data *data)
{
    char    **map;
    int     map_size;
    int     x;
    int     y;

    x = 0;
    y = 0;
    map = data->map;
    map_size = data->map_size;
    while (y < map_size)
    {
        while (map[y][x])
        {
			data->x_start = x;
			data->y_start = y;
            if (map[y][x] == '1')
                draw_square(data, 0xffffff, data->cup);
            else if (map[y][x] == '0' || map[y][x] == 'N')
            {
                if (map[y][x] == 'N')
                {
                    data->player.y = y;
                    data->player.x = x;
                }
                draw_square(data, 4868967, data->cup);
            }
            x++;
        }
        y++;
        x = 0;
    }
}

void    draw_line(t_data *data)
{
    int x;
    int y;
    int x_end;
    int y_end;
    int c;

    x = data->player.x + data->cup;
    y = data->player.y + data->cup;
    c = 0;
    x_end = x - (c * cos(data->player.r_angle));
    y_end = y - (c * sin(data->player.r_angle));
    while (c < 100)
    {   
        x_end = x - (c * cos(data->player.r_angle));
        y_end = y - (c * sin(data->player.r_angle));
        if (y_end > 0 && x_end > 0)
        {
            if (y_end < data->width_size && x_end < data->height_size)
                put_img(y_end, x_end, 0xFF0000, data);
        }
        c++;
    }
}

void    redraw(t_data *data)
{
    mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
    data->img.mlx_img = mlx_new_image(data->mlx_ptr, data->width_size, data->height_size);
    data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, \
                        &data->img.line_len, &data->img.endian);
    draw_map(data);
}
