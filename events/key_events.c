/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:12:24 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/11/01 12:31:20 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ft_draw_walls_2d(t_data *cub)
{
	size_t	i;

	i = 0;
	cub->color = 0xff;
	while (i < cub->map_rows * cub->cub)
	{
		cub->var.x_one = 0;
		cub->var.y_one = i;
		cub->var.x_two = (cub->map_collums - 1) * cub->cub;
		cub->var.y_two = i;
		ddaa(cub);
		i += cub->cub;
	}
	i = 0;
	while (i < cub->map_collums * cub->cub)
	{
		cub->var.x_one = i;
		cub->var.y_one = 0;
		cub->var.x_two = i;
		cub->var.y_two = cub->map_rows * cub->cub;
		ddaa(cub);
		i += cub->cub;
	}
}

void	ft_render(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	draw_line(data);
	draw_minimap(data);
	// ft_draw_walls_2d(data);
	data->activate = 1;
}

void	rotate_line(t_data *data, float angle)
{
	data->player.r_angle += angle;
	data->player.r_angle = remainder_angle(data->player.r_angle);
}

void	key_events(void *param)
{
	t_data	*data;
	float	x_value;
	float	y_value;

	data = (t_data *)param;
	x_value = cos((data->player.r_angle + data->angle)) * SPEED;
	y_value = sin((data->player.r_angle + data->angle)) * SPEED;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		rotate_line(data, (ROTATE * (M_PI / 180)));
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		rotate_line(data, (-ROTATE * (M_PI / 180)));
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	player_moves(data, data->mlx, x_value, y_value);
}
