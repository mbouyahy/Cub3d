/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:08:47 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/13 11:45:11 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_data(t_data  *data)
{
    //player init
    data->player.x = 0;
    data->player.y = 0;
    data->player.rad = 3;
    data->player.t_dir = 0;
    data->player.w_dir = 0;
    data->player.r_angle = M_PI / 2;
    data->player.r_speed = 3 * (M_PI / 180);
    data->player.m_speed = 50;

    //data init
    data->map = fill_array(&data->map_size);
    data->x_start = 0;
    data->y_start = 0;
    data->cup = 60;
    data->width_size = (ft_strlen(data->map[0]) - 1) * data->cup;//work with max_size in the code of jihad
    if (data->map && data->map[0])
        data->height_size = data->map_size * data->cup;
}
