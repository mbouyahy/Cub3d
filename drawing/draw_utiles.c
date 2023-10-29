/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:35:29 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/25 20:08:59 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	put_img(int x, int y, unsigned int color, t_data *data)
{
	char	*pixel;

	pixel = data->img.addr + ((y * (data->img.line_len) + (x * (data->img.bpp / 8))));
	*(unsigned int *)pixel = color;
}

void    setup_angle(t_data *data)
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
