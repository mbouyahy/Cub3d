/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:12:24 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/30 16:24:04 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void ddaa(t_data *data, int x1, int y1, int x2, int y2, int color)
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
		if (x > 0 && x < data->window_width && y > 0 && y < data->window_height)
        	mlx_put_pixel(data->image, round(x), round(y), color);
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

void 	ft_render(void *param)
{
  t_data  *data = (t_data *)param;
  // if (!data->game_started)
  //   return;
	draw_line(data);
	draw_minimap(data);
  ft_draw_walls_2d(data);
  data->activate = 1;
}

void rotate_line(t_data *data, float angle)
{
    data->player.r_angle += angle;
    data->player.r_angle = remainder_angle(data->player.r_angle);
}

int	special_check(t_data *data, float x, float y)
{
	int			grid_x;
    int			grid_y;

  grid_x = (int)(x / data->cub);
  grid_y = (int)(y / data->cub);
	if (x >= 0 && y >= 0 && x < data->window_width && y < data->window_height)
	{
		if (data->map[(int)(data->player.y / data->cub)][grid_x] == '1'
				|| data->map[grid_y][(int)(data->player.x / data->cub)] == '1')
		{
			return (1);
		}
	}
	return (0);
}

int  check_wall(t_data *data, float x_value, float y_value)
{
    int     grid_x;
    int     grid_y;
    float   x;
    float   y;
  
    x = data->player.x + x_value;
    y = data->player.y + y_value;
    if (special_check(data, x, y))
      return (1);
    if (x <= data->cub - x_value  || y <= data->cub - y_value ||
        x >= data->window_width - data->cub || y >= data->window_height - data->cub)
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

void key_events(void *param)
{
    t_data *data = (t_data *)param;
    float x_value;
    float y_value;
    
    x_value = cos((data->player.r_angle + data->angle)) * SPEED;
    y_value = sin((data->player.r_angle + data->angle)) * SPEED;
    if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
      rotate_line(data,  (ROTATE * (M_PI / 180)));
    if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
      rotate_line(data,  (-ROTATE * (M_PI / 180)));
	  if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		  mlx_close_window(data->mlx);
    player_moves(data, data->mlx, x_value, y_value);
    // if (key == ESC)
		//   destroy_window(data);
    // ft_render(data);
}
