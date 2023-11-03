/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:07:47 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/11/01 14:49:15 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	horizontal_intersection_short(t_data *data)
{
	float	x;
	float	y;

	while (data->dist.temporary_y > 0 && data->dist.temporary_x > 0)
	{
		x = data->dist.temporary_x;
		y = data->dist.temporary_y;
		if (data->ray_up)
			y -= 1;
		if (is_inside_wall(data, x, y))
		{
			data->horiz.x = data->dist.temporary_x;
			data->horiz.y = data->dist.temporary_y;
			data->horiz.iswall = TRUE;
			break ;
		}
		else
		{
			data->dist.temporary_x += data->dist.x_step;
			data->dist.temporary_y += data->dist.y_step;
		}
	}
}

void	horizontal_intersection(t_data *data)
{
	horizontal_init(data);
	setup_direction(data);
	find_coordinate(data, HORIZONTAL);
	horizontal_next_step(data);
	data->dist.temporary_x = data->dist._x;
	data->dist.temporary_y = data->dist._y;
	horizontal_intersection_short(data);
}

void	vertical_intersection_short(t_data *data)
{
	float	x;
	float	y;

	while (data->dist.temporary_y > 0 && data->dist.temporary_x > 0)
	{
		x = data->dist.temporary_x;
		if (data->ray_left)
			x -= 1;
		y = data->dist.temporary_y;
		if (is_inside_wall(data, x, y))
		{
			data->vert.x = data->dist.temporary_x;
			data->vert.y = data->dist.temporary_y;
			data->vert.iswall = TRUE;
			break ;
		}
		else
		{
			data->dist.temporary_x += data->dist.x_step;
			data->dist.temporary_y += data->dist.y_step;
		}
	}
}

void	vertical_intersection(t_data *data)
{
	vertical_init(data);
	find_coordinate(data, VERTICAL);
	vertical_next_step(data);
	data->dist.temporary_x = data->dist._x;
	data->dist.temporary_y = data->dist._y;
	vertical_intersection_short(data);
}
