/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:07:47 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/30 17:04:31 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	setup_direction(t_data *data)
{
	if (data->var.angle > 0 && data->var.angle < M_PI)
		data->ray_down = TRUE;
	else
		data->ray_down = FALSE;
	data->ray_up = !data->ray_down;
	if (data->var.angle < 0.5 * M_PI || data->var.angle > 1.5 * M_PI)
		data->ray_right = TRUE;
	else
		data->ray_right = FALSE;
	data->ray_left = !data->ray_right;
}

void	horizontal_init(t_data *data)
{
	data->Horiz.x = 0;
	data->Horiz.y = 0;
	data->Horiz.iswall = 0;
	data->dist.temporary_x = 0.0;
	data->dist.temporary_y = 0.0;
}

void	horizontal_intersection(t_data *data)
{
	float	x;
	float	y;

	horizontal_init(data);
	setup_direction(data);
	find_coordinate(data, HORIZONTAL);
	horizontal_next_step(data);
	data->dist.temporary_x = data->dist._x;
	data->dist.temporary_y = data->dist._y;
	while (data->dist.temporary_y <= data->window_height && \
		data->dist.temporary_y > 0 && data->dist.temporary_x > 0 && \
		data->dist.temporary_x <= data->window_width)
	{
		x = data->dist.temporary_x;
		y = data->dist.temporary_y;
		if (data->ray_up)
			y -= 1;
		if (is_inside_wall(data, x, y))
		{
			data->Horiz.x = data->dist.temporary_x;
			data->Horiz.y = data->dist.temporary_y;
			data->Horiz.iswall = TRUE;
			break ;
		}
		else
		{
			data->dist.temporary_x += data->dist.x_step;
			data->dist.temporary_y += data->dist.y_step;
		}
	}
}

void	vertical_init(t_data *data)
{
	data->Vert.x = 0;
	data->Vert.y = 0;
	data->dist.temporary_x = 0.0;
	data->dist.temporary_y = 0.0;
	data->Vert.iswall = 0;
}

void	vertical_intersection(t_data *data)
{
	float	x;
	float	y;

	vertical_init(data);
	find_coordinate(data, VERTICAL);
	vertical_next_step(data);
	data->dist.temporary_x = data->dist._x;
	data->dist.temporary_y = data->dist._y;
	while (data->dist.temporary_y <= data->window_height && \
		data->dist.temporary_y > 0 && data->dist.temporary_x > 0 && \
		data->dist.temporary_x <= data->window_width)
	{
		x = data->dist.temporary_x;
		if (data->ray_left)
			x -= 1;
		y = data->dist.temporary_y;
		if (is_inside_wall(data, x, y))
		{
			data->Vert.x = data->dist.temporary_x;
			data->Vert.y = data->dist.temporary_y;
			data->Vert.iswall = TRUE;
			break ;
		}
		else
		{
			data->dist.temporary_x += data->dist.x_step;
			data->dist.temporary_y += data->dist.y_step;
		}
	}
}
