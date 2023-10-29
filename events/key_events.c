/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:12:24 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/29 15:55:51 by jlaazouz         ###   ########.fr       */
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

void ddaa(t_data *cub, int x1, int y1, int x2, int y2, int color)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xIncrement = dx / (float) steps;
    float yIncrement = dy / (float) steps;
    float x = x1, y = y1;

    for (int i = 0; i < steps; ++i) {
        x += xIncrement;
        y += yIncrement;
		if (x > 0 && x < WINDOW_WIDTH && y > 0 && y < WINDOW_HEIGHT)
        	put_pixel(&cub->img, round(x), round(y), color);
    }
}

void ft_draw_walls_2d(t_data *cub)
{
	size_t i;
	
	i = 0;
	while (i < cub->map_rows * cub->cub)
	{
		ddaa(cub, 0, i,(cub->map_collums - 1) * cub->cub , i, 0xff);
		i += cub->cub;
	}
	i = 0;
	while (i < cub->map_collums * cub->cub)
	{
		ddaa(cub, i, 0, i, (cub->map_rows) * cub->cub, 0xff);
		i += cub->cub;
	}
	
}

int	ft_render(t_data *data)
{
	draw_line(data);
	draw_minimap(data);
  // ft_draw_walls_2d(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
  mlx_do_sync(data->mlx_ptr);
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
    if (x <= data->cub - x_value  || y <= data->cub - y_value ||
        x >= WINDOW_WIDTH - data->cub || y >= WINDOW_HEIGHT - data->cub)
      return (1);
    grid_x = (int)(x / data->cub);
    grid_y = (int)(y / data->cub);
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
    
    x_value = cos((data->player.r_angle + data->angle)) * SPEED;
    y_value = sin((data->player.r_angle + data->angle)) * SPEED;
    if (key == RIGHT)
      rotate_line(data,  (6 * (M_PI / 180)));
    if (key == LEFT)
      rotate_line(data,  (-6 * (M_PI / 180)));
    player_moves(data, key, x_value, y_value);
    if (key == ESC)
		  destroy_window(data);
    // ft_render(data);
    return (0);
}
