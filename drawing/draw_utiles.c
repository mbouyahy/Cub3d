/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:35:29 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/19 11:01:01 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

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
    while (j <= cub)
    {
        while (i <= cub)
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

void    setup_angle(t_data *data)
{
    if (data->player.facing_direction == NO)
    {
        data->player.r_angle = deg_to_rad(270);
    }
    else if (data->player.facing_direction == SO)
    {
        data->player.r_angle = deg_to_rad(90);
    }
    else if (data->player.facing_direction == EA)
    {
        data->player.r_angle = deg_to_rad(0);
    }
    else if (data->player.facing_direction == WE)
    {
        data->player.r_angle = deg_to_rad(180);
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
            {
                draw_square(data, 0xffffff, data->cub);
            }
            else if (data->map[y][x] == '0' || ft_strchr(MAP_DIRECTIONS, data->map[y][x]))
            {
                if (ft_strchr(MAP_DIRECTIONS, data->map[y][x]) && flag == 0)//test
                {
                    data->player.p_direction = data->map[y][x];
                    //(data->cub / 2) for put the player in the center of cub
                    data->player.y = y * data->cub + (data->cub / 2);
                    data->player.x = x * data->cub + (data->cub / 2);
                }
                draw_square(data, 4868967, data->cub);
            }
        }
        x = -1;
    }
}
