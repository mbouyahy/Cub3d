/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:08:47 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/11/01 12:30:50 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

float	deg_to_rad(float deg)
{
	return (deg * (M_PI / 180));
}

int	special_check(t_data *data, float x, float y)
{
	int	grid_x;
	int	grid_y;

	grid_x = (int)(x / data->cub);
	grid_y = (int)(y / data->cub);
	if (x >= 0 && y >= 0 && x < data->window_width && y < data->window_height)
	{
		if (data->map[(int)(data->player.y / data->cub)][grid_x] == '1'
			|| data->map[grid_y][(int)(data->player.x / data->cub)] == '1')
		{
			return (TRUE);
		}
	}
	return (FALSE);
}

int	check_wall(t_data *data, float x_value, float y_value)
{
	int		grid_x;
	int		grid_y;
	float	x;
	float	y;

	x = data->player.x + x_value;
	y = data->player.y + y_value;
	if (special_check(data, x, y))
		return (TRUE);
	if (x <= data->cub - x_value || y <= data->cub - y_value || 
		x >= data->window_width - data->cub || 
		y >= data->window_height - data->cub)
		return (TRUE);
	grid_x = (int)(x / data->cub);
	grid_y = (int)(y / data->cub);
	if (grid_x >= data->collums - 1 || grid_y >= data->rows - 1)
		return (TRUE);
	if (data->map[grid_y][grid_x] == '0' || 
		ft_strchr(MAP_DIRECTIONS, data->map[grid_y][grid_x]))
		return (FALSE);
	return (TRUE);
}

void	ddaa(t_data *data)
{
	float		stp;
	t_var		var;
	float		dx;
	float		dy;

	var.i = 0;
	dx = data->var.x_two - data->var.x_one;
	dy = data->var.y_two - data->var.y_one;
	if (fabsf(dx) > fabsf(dy))
		stp = fabsf(dx);
	else
		stp = fabsf(dy);
	var.x_inc = dx / (float) stp;
	var.y_inc = dy / (float) stp;
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
