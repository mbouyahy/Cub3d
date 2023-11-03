/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utiles_bonus_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:08:47 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/11/01 20:25:16 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

float	deg_to_rad(float deg)
{
	return (deg * (M_PI / 180));
}

int	special_check(t_data *data, float x, float y)
{
	size_t	grid_x;
	size_t	grid_y;
	size_t	p_x;
	size_t	p_y;

	grid_x = (size_t)(x / data->cub);
	grid_y = (size_t)(y / data->cub);
	p_x = (size_t)(data->player.x / data->cub);
	p_y = (size_t)(data->player.y / data->cub);
	if (x >= 0 && y >= 0 && x < data->window_width && y < data->window_height)
	{
		if (p_y < data->map_rows && grid_y < data->map_rows
			&& p_x < data->map_collums && grid_x < data->map_collums)
			if (data->map[p_y][grid_x] == '1' || data->map[grid_y][p_x] == '1')
				return (TRUE);
	}
	return (FALSE);
}

int	check_wall(t_data *data, float x_value, float y_value)
{
	size_t	grid_x;
	size_t	grid_y;
	float	x;
	float	y;

	x = data->player.x + x_value;
	y = data->player.y + y_value;
	if (special_check(data, x, y))
		return (TRUE);
	grid_x = (size_t)(x / data->cub);
	grid_y = (size_t)(y / data->cub);
	if (grid_x >= (size_t)data->collums - 1 || grid_y >= (size_t)data->rows - 1)
		return (TRUE);
	if (data->map[grid_y][grid_x] == '0' ||
		ft_strchr(MAP_DIRECTIONS, data->map[grid_y][grid_x]))
		return (FALSE);
	return (TRUE);
}

void	ddaa(t_data *data)
{
	float	stp;
	t_var	var;
	float	dx;
	float	dy;

	var.i = 0;
	dx = data->var.x_two - data->var.x_one;
	dy = data->var.y_two - data->var.y_one;
	if (fabsf(dx) > fabsf(dy))
		stp = fabsf(dx);
	else
		stp = fabsf(dy);
	var.x_inc = dx / (float)stp;
	var.y_inc = dy / (float)stp;
	var.x = data->var.x_one;
	var.y = data->var.y_one;
	while (var.i <= stp)
	{
		if (var.x >= data->window_width || var.y >= data->window_height)
			break ;
		mlx_put_pixel(data->image, var.x, var.y, data->color);
		var.x += var.x_inc;
		var.y += var.y_inc;
		var.i++;
	}
}
