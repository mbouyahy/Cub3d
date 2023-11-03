/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:24:41 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/11/01 20:55:02 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

float	abs_angle(t_data *data)
{
	if (data->var.angle > data->player.r_angle)
		return (data->var.angle - data->player.r_angle);
	else if (data->var.angle < data->player.r_angle)
		return (data->player.r_angle - data->var.angle);
	return (data->var.angle);
}

void	drawing_wall(t_data *data, int axe)
{
	float	correct_distance;
	float	projectionwall_h;
	int		top;
	int		bottom;

	if (!data->activate)
		return ;
	correct_distance = data->distance * cos(abs_angle(data));
	projectionwall_h = (data->tile / correct_distance) 
		* (data->window_width / 2) / tanf((data->fov / 2));
	top = (data->window_height - (int)projectionwall_h) / 2;
	bottom = top + projectionwall_h;
	draw_scene_line(data, top, bottom, axe);
}

float	distance_calc(t_data *data, int value)
{
	if (value == HORIZONTAL)
	{
		return (sqrt(((data->player.x - data->horiz.x) * (data->player.x
						- data->horiz.x)) + ((data->player.y - data->horiz.y)
					* (data->player.y - data->horiz.y))));
	}
	else if (value == VERTICAL)
	{
		return (sqrt(((data->player.x - data->vert.x) * (data->player.x
						- data->vert.x)) + ((data->player.y - data->vert.y)
					* (data->player.y - data->vert.y))));
	}
	return (0);
}

void	wall(t_data *data, float hor, float ver)
{
	if (hor < ver)
	{
		data->distance = hor;
		data->x_wall = data->horiz.x;
		data->y_wall = data->horiz.y;
		data->type = HORIZONTAL;
		drawing_wall(data, HORIZONTAL);
	}
	else
	{
		data->distance = ver;
		data->x_wall = data->vert.x;
		data->y_wall = data->vert.y;
		data->type = VERTICAL;
		drawing_wall(data, VERTICAL);
	}
}

void	find_distance(t_data *data)
{
	float	vertical;
	float	horizontal;

	vertical = 0;
	horizontal = 0;
	horizontal_intersection(data);
	vertical_intersection(data);
	if (data->horiz.iswall)
		horizontal = distance_calc(data, HORIZONTAL);
	else
		horizontal = MAX_I;
	if (data->vert.iswall)
		vertical = distance_calc(data, VERTICAL);
	else
		vertical = MAX_I;
	wall(data, horizontal, vertical);
}
