/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:19:39 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/27 11:21:18 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void  key_a(t_data *data, float x_value, float y_value)
{
	data->angle = ((3 * M_PI)/2);
	x_value = cos((data->player.r_angle + data->angle)) * SPEED;
    y_value = sin((data->player.r_angle + data->angle)) * SPEED;
	// printf("angle %f\n", data->player.r_angle);
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

void  player_moves(t_data *data, int key, float x_value, float y_value)
{
    if (key == A)
		key_a(data, x_value, y_value);
    else if (key == D)
		key_d(data, x_value, y_value);
    else if (key == W)
		key_w(data, x_value, y_value);
    else if (key == S)
		key_s(data, x_value, y_value);
}
