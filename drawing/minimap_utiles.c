/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:10:19 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/30 16:51:28 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	minimap_check_wall(t_data *data, float x_value, float y_value)
{
	int		grid_x;
	int		grid_y;
	float	x;
	float	y;

	x = data->minimap.x + x_value;
	y = data->minimap.y + y_value;
	if (x <= data->cub - x_value || y <= data->cub - y_value || \
		x >= data->minimap.width - data->cub || \
		y >= data->minimap.height - data->cub)
		return (1);
	grid_x = (int)(x / data->cub);
	grid_y = (int)(y / data->cub);
	if (grid_x >= data->collums - 1 || grid_y >= data->rows - 1)
		return (1);
	if (data->map[grid_y][grid_x] == '0' ||
		ft_strchr(MAP_DIRECTIONS, data->map[grid_y][grid_x]))
		return (0);
	return (1);
}
