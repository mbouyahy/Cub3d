/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:00:46 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/14 16:31:58 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_img(int x, int y, unsigned int color, t_data *data)
{
	char	*pixel;

	pixel = data->img.addr + ((y * (data->img.line_len) + (x * (data->img.bpp / 8))));
	*(unsigned int *)pixel = color;
}

void draw_square(t_data *data, int color, int cub)
{
    int i = 0;
    int j = 0;

    data->x_start *= cub;
    data->y_start *= cub;
    while (j < cub)
    {
        while (i < cub)
        {
            if (data->x_start + i < data->width_size \
				&& data->y_start + j < data->height_size)
                put_img(data->x_start + i, data->y_start + j, color, data);
            i++;
        }
        i = 0;
        j++;
    }
}

void    draw_map(t_data *data, int flag)
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
                draw_square(data, 0xffffff, data->cub);
            else if (data->map[y][x] == '0' || data->map[y][x] == 'N'\
                     || data->map[y][x] == 'W' || data->map[y][x] == 'E'\
                        || data->map[y][x] == 'S')
            {
                if ((data->map[y][x] == 'N' || data->map[y][x] == 'W'\
                     || data->map[y][x] == 'E' || data->map[y][x] == 'S')\
                         && flag == 0)
                {
                    data->player.p_direction = data->map[y][x];
                    data->player.y = y * data->cub + (data->cub / 2);//(data->cub / 2) for put the player in the center of cub
                    data->player.x = x * data->cub + (data->cub / 2);//(data->cub / 2) for put the player in the center of cub
                }
                draw_square(data, 4868967, data->cub);
            }
            put_img(data->x_start--, data->y_start--, 0, data);
        }
        x = -1;
    }
    vertical_intersection(data);
}

void    setup_angle(t_data *data)
{
    if (data->player.p_direction == 'N')
    {
        data->player.r_angle = deg_to_rad(90);
    }
    else if (data->player.p_direction == 'E')
    {
        data->player.r_angle = deg_to_rad(180);
    }
    else if (data->player.p_direction == 'S')
    {
        data->player.r_angle = deg_to_rad(270);
    }
    else if (data->player.p_direction == 'W')
    {
        data->player.r_angle = deg_to_rad(360);
    }
}

void    draw_line(t_data *data)
{
    t_var	var;
    int		x_end;
    int		y_end;
    double  angle;
    int     n_lines;

    x_end = 0;
    y_end = 0;
    var.c = 1;
    var.x = data->player.x;
    var.y = data->player.y;
    angle = data->player.r_angle;
    n_lines = 60;
    while (--n_lines)
    {
        while (var.c < 500)
        {   
            x_end = var.x - (var.c * cos(angle));
            y_end = var.y - (var.c * sin(angle));
            if (y_end > 0 && x_end > 0)
            {
                if (x_end < data->width_size && y_end < data->height_size)
                    put_img(x_end, y_end, 0xFF0000, data);
            }
            var.c++;
        }
        angle += deg_to_rad(60) / data->height_size * 5;
        var.c = 1;
    }
}

void    redraw(t_data *data, int flag)
{
    mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
    data->img.mlx_img = mlx_new_image(data->mlx_ptr, data->width_size, data->height_size);
    data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, \
                        &data->img.line_len, &data->img.endian);
    draw_map(data, flag);
}
