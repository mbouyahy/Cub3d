/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:53:41 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/31 18:19:32 by mbouyahy         ###   ########.fr       */
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
	data->color = 0xFF0000FF;
	if (data->type == HORIZONTAL)
	{
		data->var.x_one = data->player.x;
		data->var.y_one = data->player.y;
		data->var.x_two = data->Horiz.x;
		data->var.y_two = data->Horiz.y;
		ddaa(data);
	}
	else if (data->type == VERTICAL)
	{
		data->var.x_one = data->player.x;
		data->var.y_one = data->player.y;
		data->var.x_two = data->Vert.x;
		data->var.y_two = data->Vert.y;
		ddaa(data);
	}
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
