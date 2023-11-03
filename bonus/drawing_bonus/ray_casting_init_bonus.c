/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_init_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:50:01 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/11/01 20:25:16 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

void	horizontal_init(t_data *data)
{
	data->horiz.x = 0;
	data->horiz.y = 0;
	data->horiz.iswall = 0;
	data->dist.temporary_x = 0.0;
	data->dist.temporary_y = 0.0;
}

void	vertical_init(t_data *data)
{
	data->vert.x = 0;
	data->vert.y = 0;
	data->dist.temporary_x = 0.0;
	data->dist.temporary_y = 0.0;
	data->vert.iswall = 0;
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
