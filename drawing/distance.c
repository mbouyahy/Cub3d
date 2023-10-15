/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:07:47 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/15 19:35:05 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	find_coordinate(t_data *data, int next_point, double *step)
{
	//N => UP | S => DOWN
	if (data->player.p_direction == 'N' || data->player.p_direction == 'W')
	{
		*step = data->cub * -1;
		//be rounded down | i removed -1
		return ((int)roundf(next_point/data->cub) * data->cub - 1);
	}
	else if (data->player.p_direction == 'S' || data->player.p_direction == 'E')
	{
		*step = data->cub;
		//be rounded down
		return ((int)roundf(next_point/data->cub) * data->cub + data->cub);
	}
	return (0);
}

int	distance_calc(t_data *data, t_distance distance)
{
	return (((data->player.x - distance.next_x) * (data->player.x - distance.next_x))\
				 + ((data->player.y - distance.next_y) * (data->player.y - distance.next_y)));
}

int	vertical_intersection(t_data *data)
{
	t_distance distance;

	distance.y_step = data->cub * tan(deg_to_rad(60));
	distance.next_x = find_coordinate(data, data->player.x, &distance.x_step);
	distance.grid_x = (distance.next_x / data->cub);
	distance.next_y = data->player.y + ((data->player.x - distance.next_x) * tan(deg_to_rad(60)));//
	distance.grid_y = (distance.next_y / data->cub);
	distance.v_dist = 0;
	while (distance.next_y < data->height_size && distance.next_y >= 0\
		 && distance.next_x >= 0 && distance.next_x < data->width_size)
	{
		if (data->map[distance.grid_y][distance.grid_x] == '1')
			return (distance_calc(data, distance));
		distance.next_y += distance.y_step;
		distance.grid_y = (distance.next_y / data->cub);
		distance.next_x += distance.x_step;
		distance.grid_x = (distance.next_x / data->cub);
	}
	return (0);
}

int	horizontal_intersection(t_data *data)
{
	t_distance distance;

	distance.x_step = data->cub / tan(deg_to_rad(60));
	distance.next_y = find_coordinate(data, data->player.y, &distance.y_step);
	distance.grid_y = (distance.next_y / data->cub);
	distance.next_x = data->player.x + ((data->player.y - distance.next_y) / tan(deg_to_rad(60)));
	distance.grid_x = (distance.next_x / data->cub);
	while (distance.next_y < data->height_size && distance.next_y >= 0\
		 && distance.next_x >= 0 && distance.next_x < data->width_size)
	{
		if (data->map[distance.grid_y][distance.grid_x] == '1')
			return (distance_calc(data, distance));
		distance.next_y += distance.y_step;
		distance.grid_y = (distance.next_y / data->cub);
		distance.next_x += distance.x_step;
		distance.grid_x = (distance.next_x / data->cub);
	}
	return (0);
}
