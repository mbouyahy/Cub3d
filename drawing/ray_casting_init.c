/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:50:01 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/31 17:52:55 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	horizontal_init(t_data *data)
{
	data->Horiz.x = 0;
	data->Horiz.y = 0;
	data->Horiz.iswall = 0;
	data->dist.temporary_x = 0.0;
	data->dist.temporary_y = 0.0;
}

void	vertical_init(t_data *data)
{
	data->Vert.x = 0;
	data->Vert.y = 0;
	data->dist.temporary_x = 0.0;
	data->dist.temporary_y = 0.0;
	data->Vert.iswall = 0;
}

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
