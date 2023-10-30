/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:19:39 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/30 16:24:22 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void  key_a(t_data *data, float x_value, float y_value)
{
	data->angle = ((3 * M_PI)/2);
	x_value = cos((data->player.r_angle + data->angle)) * SPEED;
    y_value = sin((data->player.r_angle + data->angle)) * SPEED;
    if (!check_wall(data, x_value, y_value))
	{
		data->player.x += x_value;
		data->player.y += y_value;
	}
	if (!minimap_check_wall(data, x_value, y_value))
	{
		data->minimap.x += x_value;
		data->minimap.y += y_value;
	}
}

void	key_d(t_data *data, float x_value, float y_value)
{
	data->angle = M_PI/2;
	x_value = cos((data->player.r_angle + data->angle)) * SPEED;
    y_value = sin((data->player.r_angle + data->angle)) * SPEED;
	if (!check_wall(data, x_value, y_value))
	{
		data->player.x += x_value;
		data->player.y += y_value;
	}
	if (!minimap_check_wall(data, x_value, y_value))
	{
		data->minimap.x += x_value;
		data->minimap.y += y_value;
	}
}

void	key_w(t_data *data, float x_value, float y_value)
{
	data->angle = 0;
    x_value = cos((data->player.r_angle + data->angle)) * SPEED;
    y_value = sin((data->player.r_angle + data->angle)) * SPEED;
	if (!check_wall(data, x_value, y_value))
	{
		data->player.x += x_value;
		data->player.y += y_value;
	}
	if (!minimap_check_wall(data, x_value, y_value))
	{
		data->minimap.x += x_value;
		data->minimap.y += y_value;
	}
}

void	key_s(t_data *data, float x_value, float y_value)
{
	data->angle = 0;
    x_value = cos((data->player.r_angle + data->angle)) * SPEED;
    y_value = sin((data->player.r_angle + data->angle)) * SPEED;
	if (!check_wall(data, -x_value, -y_value))
	{
		data->player.x -= x_value;
		data->player.y -= y_value;
	}
	if (!minimap_check_wall(data, -x_value, -y_value))
	{
		data->minimap.x -= x_value;
		data->minimap.y -= y_value;
	}
}

void  player_moves(t_data *data, mlx_t *mlx, float x_value, float y_value)
{
    if (mlx_is_key_down(mlx, MLX_KEY_A))
		key_a(data, x_value, y_value);
    if (mlx_is_key_down(mlx, MLX_KEY_D))
		key_d(data, x_value, y_value);
    if (mlx_is_key_down(mlx, MLX_KEY_W))
		key_w(data, x_value, y_value);
    if (mlx_is_key_down(mlx, MLX_KEY_S))
		key_s(data, x_value, y_value);
}
