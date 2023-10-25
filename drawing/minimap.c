/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:53:41 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/25 19:40:42 by mbouyahy         ###   ########.fr       */
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
            {
                draw_square(data, 0xffffff, data->cub);
            }
            else if (data->map[y][x] == '0' || ft_strchr(MAP_DIRECTIONS, data->map[y][x]))
            {
                if (ft_strchr(MAP_DIRECTIONS, data->map[y][x]) && flag == 0)//test
                {
                    // data->player.p_direction = data->map[y][x];
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
