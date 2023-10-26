/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:12:24 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/26 13:46:43 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	ft_render(t_data *data)
{
  draw_map(data, 0);//you can deactivate this map and work only with the 3d!(🤡) map
  draw_line(data);
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
    if (x <= data->cub - x_value  || y <= data->cub - y_value ||
        x >= data->width_size - data->cub || y >= data->height_size - data->cub)
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

void  player_moves(t_data *data, int key, float x_value, float y_value)
{
    if (key == A)
    {
      if (!check_wall(data, x_value - (M_PI / 2), y_value - (M_PI / 2)))
      {
        data->var.move_x += (x_value - (M_PI / 2));
        data->var.move_y += (y_value - (M_PI / 2));
      }
    }
    if (key == D)
    {
      if (!check_wall(data, x_value + (M_PI / 2), y_value + (M_PI / 2)))
      {
        data->var.move_x += (x_value + (M_PI / 2));
        data->var.move_y += (y_value + (M_PI / 2));
      }
    }
    if (key == W)
    {
      if (!check_wall(data, x_value, y_value))
      {
        data->var.move_x += x_value;
        data->var.move_y += y_value;
      }
    }
    if (key == S)
    {
      if (!check_wall(data, -x_value, -y_value))
      {
        data->var.move_x -= x_value;
        data->var.move_y -= y_value;
      }
    }
}

int key_events(int key, t_data *data)
{
    float x_value;
    float y_value;

    x_value = cos((data->player.r_angle));
    y_value = sin((data->player.r_angle));
    if (key == RIGHT)
      rotate_line(data,  (5 * (M_PI / 180)));
    if (key == LEFT)
      rotate_line(data,  (-5 * (M_PI / 180)));
    //maybe the movement events not working yet
    player_moves(data, key, x_value, y_value);
    if (key == ESC)
		  destroy_window(data);
    ft_render(data);
    return (0);
}
