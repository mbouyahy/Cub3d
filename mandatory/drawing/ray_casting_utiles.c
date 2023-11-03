/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_utiles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:30:23 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/11/01 12:30:20 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	find_coordinate(t_data *data, int value)
{
	if (value == HORIZONTAL)
	{
		data->dist._y = (int)(data->player.y / data->cub) * data->cub;
		if (data->ray_down)
			data->dist._y += data->cub;
		else
			data->dist._y += 0;
		data->dist._x = data->player.x + (data->dist._y - data->player.y)
			/ tan(data->var.angle);
	}
	else if (value == VERTICAL)
	{
		data->dist._x = (int)(data->player.x / data->cub) * data->cub;
		if (data->ray_right)
			data->dist._x += data->cub;
		else
			data->dist._x += 0;
		data->dist._y = data->player.y + (data->dist._x - data->player.x)
			* tan(data->var.angle);
	}
}

float	remainder_angle(float angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle += (2 * M_PI);
	return (angle);
}

void	horizontal_next_step(t_data *data)
{
	data->dist.y_step = data->cub;
	if (data->ray_up)
		data->dist.y_step *= -1;
	data->dist.x_step = data->cub / tan(data->var.angle);
	if (data->ray_left && data->dist.x_step > 0)
		data->dist.x_step *= -1;
	else if (data->ray_right && data->dist.x_step < 0)
		data->dist.x_step *= -1;
}

void	vertical_next_step(t_data *data)
{
	data->dist.x_step = data->cub;
	if (data->ray_left)
		data->dist.x_step *= -1;
	data->dist.y_step = data->cub * tan(data->var.angle);
	if (data->ray_up && data->dist.y_step > 0)
		data->dist.y_step *= -1;
	else if (data->ray_down && data->dist.y_step < 0)
		data->dist.y_step *= -1;
}

int	is_inside_wall(t_data *data, float x, float y)
{
	int	grid_x;
	int	grid_y;

	grid_y = (int)(y / data->cub);
	grid_x = (int)(x / data->cub);
	if (grid_y >= data->rows)
		return (TRUE);
	if ((size_t)grid_x >= ft_strlen(data->map[grid_y]))
		return (TRUE);
	if (grid_x <= 0 || grid_y <= 0)
		return (TRUE);
	if (data->map[grid_y][grid_x] == '1')
		return (TRUE);
	return (FALSE);
}
