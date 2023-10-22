/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:35:29 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/21 18:19:34 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void    setup_angle(t_data *data)
{
    if (data->player.facing_direction == NO)
    {
        data->player.r_angle = deg_to_rad(270);
    }
    else if (data->player.facing_direction == SO)
    {
        data->player.r_angle = deg_to_rad(90);
    }
    else if (data->player.facing_direction == EA)
    {
        data->player.r_angle = deg_to_rad(0);
    }
    else if (data->player.facing_direction == WE)
    {
        data->player.r_angle = deg_to_rad(180);
    }
}

void    redraw(t_data *data, int flag)
{
    mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
    data->img.mlx_img = mlx_new_image(data->mlx_ptr, data->width_size, data->height_size);
    data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, \
                        &data->img.line_len, &data->img.endian);
    // draw_map(data, flag);
    (void)flag;
}
