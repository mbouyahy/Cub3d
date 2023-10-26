/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:19:39 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/26 22:02:18 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void  key_a(t_data *data, float x_value, float y_value)
{
    if (!check_wall(data, x_value - (M_PI / 2), y_value - (M_PI / 2)))
	{
		data->player.x += (x_value - (M_PI / 2));
		data->player.y += (y_value - (M_PI / 2));
	}
	if (!minimap_check_wall(data, x_value - (M_PI / 2), y_value - (M_PI / 2)))
	{
		data->minimap.x += (x_value - (M_PI / 2));
		data->minimap.y += (y_value - (M_PI / 2));
	}
}

void	key_d(t_data *data, float x_value, float y_value)
{
	if (!check_wall(data, x_value + (M_PI / 2), y_value + (M_PI / 2)))
	{
		data->player.x += (x_value + (M_PI / 2));
		data->player.y += (y_value + (M_PI / 2));
	}
	if (!minimap_check_wall(data, x_value + (M_PI / 2), y_value + (M_PI / 2)))
	{
		data->minimap.x += (x_value + (M_PI / 2));
		data->minimap.y += (y_value + (M_PI / 2));
	}
}

void	key_w(t_data *data, float x_value, float y_value)
{
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
    if (key == D)
		key_d(data, x_value, y_value);
    if (key == W)
		key_w(data, x_value, y_value);
    if (key == S)
		key_s(data, x_value, y_value);
}
