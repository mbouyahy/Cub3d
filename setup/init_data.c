/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:08:47 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/11/01 12:31:37 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ft_init(t_data *data)
{
	data->file = NULL;
	data->file_len = 0;
	data->map_rows = 0;
	data->map_start = 0;
	data->visuals_len = 0;
	data->file_len = 0;
	data->map_collums = 0;
	data->map_grid = NULL;
	data->visual_data = NULL;
	data->visuals = (t_visuals *)ft_calloc(1, sizeof(t_visuals));
	data->mouse.old_x = 0;
	data->mouse.old_y = 0;
	data->mouse.new_x = 0;
	data->mouse.new_y = 0;
	data->game_started = 0;
}

void	init_data(t_data *data)
{
	data->angle = 0;
	data->map = data->map_grid;
	data->map_size = data->map_rows;
	data->x_start = 0;
	data->y_start = 0;
	data->cub = 20;
	data->fov = 60.0 * (M_PI / 180);
	data->collums = data->map_collums - 1;
	data->rows = data->map_rows;
	data->window_height = WINDOW_HEIGHT;
	data->window_width = WINDOW_WIDTH;
	data->minimap.height = data->window_height / 3;
	data->minimap.width = data->window_width / 3;
	if (data->map_collums * data->cub > (size_t)(data->window_width / 3))
		data->cub = (data->window_width / 3) / data->map_collums;
	if (data->map_rows * data->cub > (size_t)(data->window_height / 3))
		data->cub = (data->window_height / 3) / data->map_rows;
	if (!data->cub || data->cub <= 0)
		data->cub = 2;
	data->tile = data->cub;
	data->activate = 1;
	data->player.y = data->player.y * data->cub + (data->cub / 2);
	data->player.x = data->player.x * data->cub + (data->cub / 2);
	setup_angle(data);
}
