/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:12:24 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/26 22:19:38 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void    redraw(t_data *data)
{
    mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
    data->img.mlx_img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
    data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, \
                        &data->img.line_len, &data->img.endian);
}

int	ft_render(t_data *data)
{
	redraw(data);
	draw_line(data);
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

void rotate_line(t_data *data, float angle)
{
    data->player.r_angle += angle;
    data->player.r_angle = remainder_angle(data->player.r_angle);
}

int  check_wall(t_data *data, float x_value, float y_value)
{
    int     grid_x;
    int     grid_y;
    float   x;
    float   y;
  
    x = data->player.x + x_value;
    y = data->player.y + y_value;
    if (x <= CUB_SIZE - x_value  || y <= CUB_SIZE - y_value ||
        x >= WINDOW_WIDTH - CUB_SIZE || y >= WINDOW_HEIGHT - CUB_SIZE)
      return (1);
    grid_x = (int)(x / CUB_SIZE);
    grid_y = (int)(y / CUB_SIZE);
    if (grid_x >= data->collums - 1 || grid_y >= data->rows - 1)
      return (1);
    if (data->map[grid_y][grid_x] == '0' || 
        ft_strchr(MAP_DIRECTIONS, data->map[grid_y][grid_x]))
      return (0);
    return (1);
}

int key_events(int key, t_data *data)
{
    float x_value;
    float y_value;

    x_value = cos((data->player.r_angle)) * 10;
    y_value = sin((data->player.r_angle)) * 10;
    if (key == RIGHT)
      rotate_line(data,  (5 * (M_PI / 180)));
    if (key == LEFT)
      rotate_line(data,  (-5 * (M_PI / 180)));
    player_moves(data, key, x_value, y_value);
    if (key == ESC)
		  destroy_window(data);
    ft_render(data);
    return (0);
}
