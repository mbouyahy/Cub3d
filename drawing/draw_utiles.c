/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:35:29 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/30 16:30:17 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	setup_angle(t_data *data)
{
	if (data->player.facing_direction == NO)
		data->player.r_angle = deg_to_rad(270);
	else if (data->player.facing_direction == SO)
		data->player.r_angle = deg_to_rad(90);
	else if (data->player.facing_direction == EA)
		data->player.r_angle = deg_to_rad(0);
	else if (data->player.facing_direction == WE)
		data->player.r_angle = deg_to_rad(180);
}
