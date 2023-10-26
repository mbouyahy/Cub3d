/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:07:47 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/26 17:18:34 by mbouyahy         ###   ########.fr       */
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
	float x;
	float y;

	//init variables
	horizontal_init(data);
	//setup ray_facing BEGIN
	setup_direction(data);
	//setup ray_facing END

	//find coordinate BEGIN
	find_coordinate(data, HORIZONTAL);
	//find coordinate END 

	//find the next x and y steps BEGIN
	horizontal_next_step(data);
	//find the next x and y steps END

	data->dist.temporary_x = data->dist._x;
	data->dist.temporary_y = data->dist._y;
	while (data->dist.temporary_y <= WINDOW_HEIGHT && data->dist.temporary_y > 0\
		&& data->dist.temporary_x > 0 && data->dist.temporary_x <= WINDOW_WIDTH)
	{
		x = data->dist.temporary_x;//testing
		y = data->dist.temporary_y;
		// float y = temp_y + (data->ray_up ? -1 : 0);//testing
		if (data->ray_up)
			y -= 1;
		if (is_inside_wall(data, x, y))
		{
			data->Horiz.x = data->dist.temporary_x;
			data->Horiz.y = data->dist.temporary_y;
			if (data->Horiz.x == 0 && data->Horiz.y == 0)
			{
				data->Horiz.x = 40;
				data->Horiz.y = 40;
			}
			data->Horiz.iswall = TRUE;
			// return (intersection_point);
			break ;
		}
		else
		{
			data->dist.temporary_x += data->dist.x_step;
			data->dist.temporary_y += data->dist.y_step;
		}
	}
	// return (intersection_point);
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
	float x;
	float y;

	//init variables
	vertical_init(data);
	//find coordinate BEGIN
	find_coordinate(data, VERTICAL);
	//find coordinate END
	
	//find the next x and y steps BEGIN
	vertical_next_step(data);
	//find the next x and y steps END

	data->dist.temporary_x = data->dist._x;
	data->dist.temporary_y = data->dist._y;
	while (data->dist.temporary_y <= WINDOW_HEIGHT && data->dist.temporary_y > 0\
		 && data->dist.temporary_x > 0 && data->dist.temporary_x <= WINDOW_WIDTH)
	{
		x = data->dist.temporary_x;
		if (data->ray_left)
			x -= 1;
		y = data->dist.temporary_y;
		if (is_inside_wall(data, x, y))
		{
			//save point (x,y)
			data->Vert.x = data->dist.temporary_x;
			data->Vert.y = data->dist.temporary_y;
			if (data->Vert.x == 0 && data->Vert.y == 0)
			{
				data->Vert.x = 40;
				data->Vert.y = 40;
			}
			data->Vert.iswall = TRUE;
			// return (data->points);
			break ;
		}
		else
		{
			data->dist.temporary_x += data->dist.x_step;
			data->dist.temporary_y += data->dist.y_step;
		}
	}
	// return (data->points);
}
