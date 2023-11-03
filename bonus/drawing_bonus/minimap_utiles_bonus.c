/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utiles_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:10:19 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/11/01 20:54:27 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

int	minimap_check_wall(t_data *data, float x_value, float y_value)
{
	int		grid_x;
	int		grid_y;
	float	x;
	float	y;

	x = data->minimap.x + x_value;
	y = data->minimap.y + y_value;
	if (x <= data->cub - x_value || y <= data->cub - y_value
		|| x >= data->minimap.width - data->cub
		|| y >= data->minimap.height - data->cub)
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

void	player_draw(t_data *data)
{
	int			x;
	int			y;
	float		i;
	float		j;
	const int	c = 3;

	j = 0;
	while (j < c)
	{
		i = 0;
		while (i < (2 * M_PI))
		{
			x = data->player.x + j * cos(i);
			y = data->player.y + j * sin(i);
			mlx_put_pixel(data->image, x, y, 0x00FF00FF);
			i = i + (float)(M_PI / 180);
		}
		j++;
	}
}
