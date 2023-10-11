/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:00:46 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/11 20:18:04 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cup3d.h"

void	put_img(int x, int y, unsigned int color, t_data *data)
{
	char	*pixel;

	pixel = data->addr + ((y * (data->line_len) + (x * (data->bpp / 8))));
	*(unsigned int *)pixel = color;
}

void draw_sq(t_data *data, int color, int cup)
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
            // printf("data->x_start + i = %d, data->y_start + j = %d\n", data->x_start + i, data->y_start + j);
            i++;
        }
        i = 0;
        j++;
    }
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->mlx_img, 0, 0);
}

void    draw_map(t_data *data)
{
    char **map;
    int map_size;
    int x;
    int y;

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
                draw_sq(data, 0xffffff, data->cup);
            else if (map[y][x] == '0')
                draw_sq(data, 4868967, data->cup);
            else if (map[y][x] == 'N')
            {
                data->gamer.pos_x = x;
                data->gamer.pos_y = y;
                // draw_sq(data, 7878678, data->cup);//test
                draw_sq(data, 4868967, data->cup);
            }
            x++;
        }
        y++;
        x = 0;
    }
}
