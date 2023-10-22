/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:07:47 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/22 18:06:47 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"


void	find_coordinate(t_data *data, t_distance *distance, float angle, int value)
{
	if (value == HORIZONTAL)
	{
		//y coordinate
		distance->next_y = floor(data->player.y / CUB_SIZE) * CUB_SIZE;
		if (distance->ray_down)
			distance->next_y += CUB_SIZE;

		//x coordinate
		distance->next_x = data->player.x + (distance->next_y - data->player.y) / tan(angle);
	}
	else if (value == VERTICAL)
	{
		//X coordinate
		distance->next_x = floor(data->player.x / CUB_SIZE) * CUB_SIZE;
		if (distance->ray_right)
			distance->next_x += CUB_SIZE;

		//Y coordinate
		distance->next_y = data->player.y + (distance->next_x - data->player.x) * tan(angle);
	}
}

float	remainder_angle(float angle)
{
	angle = remainder(angle, 2 * M_PI);
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}

void	setup_ray_facing(t_distance *distance, float angle)
{
	// if (angle > 0 && angle < M_PI)
	// 	distance->ray_down = TRUE;
	// distance->ray_up = !(distance->ray_down);
	// if (angle < 0.5 * M_PI || angle > 1.5 * M_PI)//0.5 => PI / 2,...
	// 	distance->ray_right = TRUE;
	// distance->ray_left = !(distance->ray_right);

	distance->ray_down = angle > 0 && angle < M_PI;
	distance->ray_up = !(distance->ray_down);
	distance->ray_right = angle < 0.5 * M_PI || angle > 1.5 * M_PI;
	distance->ray_left = !(distance->ray_right);
	// printf("distance->ray_down %d\n", distance->ray_down);
}

void	next_step(t_distance *distance, float angle)
{
	//y next step
	distance->y_step = CUB_SIZE;
	// if (distance->ray_up)
	// 	distance->y_step *= -1;
	distance->y_step *= distance->ray_up ? -1 : 1;
	
	//x next step
	distance->x_step = CUB_SIZE / tan(angle);
	distance->x_step *= (distance->ray_left && distance->x_step > 0) ? -1 : 1;
	distance->x_step *= (distance->ray_right && distance->x_step < 0) ? -1 : 1;
	// if (distance->ray_left && distance->x_step > 0)
	// 	distance->x_step *= -1;
	// if (distance->ray_right && distance->x_step < 0)
	// 	distance->x_step *= -1;
}

void	vertical_next_step(t_distance *distance, float angle)
{
	//x next step
	distance->x_step = CUB_SIZE;
	// if (distance->ray_left)
	// 	distance->x_step *= -1;
	distance->x_step *= distance->ray_left ? -1 : 1;
	
	//y next step
	// distance->y_step = CUB_SIZE * tan(angle);
	// if (distance->ray_up && distance->y_step > 0)
	// 	distance->y_step *= -1;
	// if (distance->ray_down && distance->y_step < 0)
	// 	distance->y_step *= -1;
	distance->y_step = CUB_SIZE * tan(angle);
	distance->y_step *= (distance->ray_up && distance->y_step > 0) ? -1 : 1;
	distance->y_step *= (distance->ray_down && distance->y_step < 0) ? -1 : 1;//test
	// printf("y_step : %f\n", distance->y_step);

}

int	is_inside_wall(t_data *data, t_distance *distance, float x, float y)
{
	//testing
	if (x < 0 || x > data->width_size || y < 0 || y > data->height_size)
		return (FALSE);
	(void)x;
	(void)y;
	distance->grid_x = (int)floor(x / CUB_SIZE);
	distance->grid_y = (int)floor(y / CUB_SIZE);
	if (data->map[distance->grid_y][distance->grid_x] == '1')
	{
		return (TRUE);
	}
	// int size_clm = data->map_collums;
	// if (distance->grid_y < data->map_size\
	// 	&& distance->grid_x < size_clm && data->map[distance->grid_y][distance->grid_x] == '1')
	// {
	// 	return (TRUE);
	// }
	return (FALSE);
}

// int	horizontal_intersection(t_data *data, float angle)
t_point	horizontal_intersection(t_data *data, float angle)
{
	t_point intersection_point;
	t_distance distance;
	float temp_x;
	float temp_y;

	intersection_point.x = -1;
	intersection_point.y = -1;
	intersection_point.is_vertical = -1;
	temp_x = 0.0;
	temp_y = 0.0;
	
	angle = remainder_angle(angle);
	setup_ray_facing(&distance, angle);

	//find coordinate
	find_coordinate(data, &distance, angle, HORIZONTAL);

	//find the next x and y steps
	next_step(&distance, angle);

	temp_x = distance.next_x;//testing
	temp_y = distance.next_y;//testing
	while (temp_y < data->height_size && temp_y >= 0\
		&& temp_x >= 0 && temp_x < data->width_size)
	{
		float x = temp_x;//testing
		float y = temp_y + (distance.ray_up ? -1 : 0);//testing
		// if (distance.ray_up)
		// 	y = temp_y - 1;
		if (is_inside_wall(data, &distance, x, y))
		{
			//save point (x,y)
			intersection_point.x = temp_x;
			intersection_point.y = temp_y;
			intersection_point.angle = angle;
			intersection_point.is_vertical = FALSE;
			return (intersection_point);
		}
		else
		{
			temp_x += distance.x_step;
			temp_y += distance.y_step;
		}
	}
	return (intersection_point);
}

t_point	vertical_intersection(t_data *data, float angle)
{
	t_point intersection_point;
	t_distance distance;
	float temp_x;
	float temp_y;

	intersection_point.x = -1;
	intersection_point.y = -1;
	temp_x = 0.0;
	temp_y = 0.0;
	intersection_point.is_vertical = -1;
	
	angle = remainder_angle(angle);
	setup_ray_facing(&distance, angle);

	//find coordinate
	find_coordinate(data, &distance, angle, VERTICAL);

	//find the next x and y steps
	vertical_next_step(&distance, angle);

	temp_x = distance.next_x;//testing
	temp_y = distance.next_y;//testing
	while (temp_y < data->height_size && temp_y >= 0\
		 && temp_x >= 0 && temp_x < data->width_size)
	{
		float x = temp_x + (distance.ray_left ? -1 : 0);//testing
		// float x = temp_x;//testing
		// if (distance.ray_left)
		// 	x = temp_x - 1;
		float y = temp_y;//testing
		// printf("HERE\n");
		if (is_inside_wall(data, &distance, x, y))
		{
			//save point (x,y)
			intersection_point.x = temp_x;
			intersection_point.y = temp_y;
			intersection_point.angle = angle;
			intersection_point.is_vertical = TRUE;
			return (intersection_point);
		}
		else
		{
			temp_x += distance.x_step;
			temp_y += distance.y_step;
		}
	}
	return (intersection_point);
}
