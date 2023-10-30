/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:53:41 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/30 16:59:55 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	draw_square(t_data *data, int color, int cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->x_start *= cub;
	data->y_start *= cub;
	while (j <= cub)
	{
		while (i <= cub)
		{
			if (data->x_start + i < data->minimap.width \
				&& data->y_start + j < data->minimap.height)
				mlx_put_pixel(data->image, data->x_start + i, \
					data->y_start + j, color);
			i++;
		}
		i = 0;
		j++;
	}
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;

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
				draw_square(data, 0xFFFFFFFF, data->cub);
			}
			else if (data->map[y][x] == '0' || \
				ft_strchr(MAP_DIRECTIONS, data->map[y][x]))
				draw_square(data, 0x2020201, data->cub);
		}
		x = -1;
	}
}

void	draw_single_line(t_data *data)
{
	if (data->type == HORIZONTAL)
		ddaa(data, data->player.x, data->player.y, data->Horiz.x, \
			data->Horiz.y, 0xFF0000FF);
	else if (data->type == VERTICAL)
		ddaa(data, data->player.x, data->player.y, data->Vert.x, \
			data->Vert.y, 0xFF0000FF);
}

void	init_var_(t_data *data, t_var *var)
{
	var->c = 1;
	var->i = 0;
	data->minimap.x = (data->player.x / data->cub) * data->cub;
	data->minimap.y = (data->player.y / data->cub) * data->cub;
	var->x = data->player.x;
	var->y = data->player.y;
	data->player.x = data->minimap.x;
	data->player.y = data->minimap.y;
	data->var.height = data->window_height;
	data->var.width = data->window_width;
	data->window_height = data->minimap.height;
	data->window_width = data->minimap.width;
	data->var.angle = data->player.r_angle - (data->fov / 2);
	var->angle_inc = data->fov / data->minimap.width;
}

void	draw_minimap(t_data *data)
{
	t_var	var;

	draw_map(data);
	init_var_(data, &var);
	data->activate = 0;
	while (var.i < data->minimap.width)
	{
		data->var.angle = remainder_angle(data->var.angle);
		find_distance(data);
		draw_single_line(data);
		data->var.angle += var.angle_inc;
		var.i++;
	}
	data->player.x = var.x;
	data->player.y = var.y;
	data->window_height = data->var.height;
	data->window_width = data->var.width;
}
