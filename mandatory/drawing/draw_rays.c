/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:00:46 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/30 16:28:13 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	init_var(t_data *data)
{
	data->var.c = 1;
	data->var.i = 0;
	data->var.x = data->player.x;
	data->var.y = data->player.y;
	data->var.x_end = 0;
	data->var.y_end = 0;
	data->var.angle = data->player.r_angle - (data->fov / 2);
	data->player.r_angle = remainder_angle(data->player.r_angle);
	data->var.angle_inc = data->fov / data->window_width;
}

void	draw_line(t_data *data)
{
	init_var(data);
	while (data->var.i < data->window_width)
	{
		data->var.angle = remainder_angle(data->var.angle);
		find_distance(data);
		data->var.angle += data->var.angle_inc;
		data->var.i++;
	}
}
