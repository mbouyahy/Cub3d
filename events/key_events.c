/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:12:24 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/25 20:18:15 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	ft_render(t_data *data)
{
  draw_map(data, 0);//you can deactivate this map and work only with the 3d!(🤡) map
  draw_line(data);
  mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

void rotate_line(t_data *data, float angle)
{
    data->player.r_angle += angle;
}

int key_events(int key, t_data *data)
{
    if (key == RIGHT)
    {
      rotate_line(data,  (5 * (M_PI / 180)));
      data->player.r_angle = remainder_angle(data->player.r_angle);
    }
    if (key == LEFT)
    {
      rotate_line(data,  (-5 * (M_PI / 180)));
      data->player.r_angle = remainder_angle(data->player.r_angle);
    }

    //maybe the movement event not working yet
    if (key == A)
    {
      data->var.move_x += (cos((data->player.r_angle))* 3);
      data->var.move_y += (sin((data->player.r_angle))* 3);
    }
    if (key == D)
    {
      data->var.move_x += (cos((data->player.r_angle))* 3);
      data->var.move_y += (sin((data->player.r_angle))* 3);
    }
    if (key == W)
    {
      data->var.move_x += (cos((data->player.r_angle))* 3);
      data->var.move_y += (sin((data->player.r_angle))* 3);
    }
    if (key == S)
    {
      data->var.move_x -= (cos((data->player.r_angle))* 3);
      data->var.move_y -= (sin((data->player.r_angle))* 3);
    }
    if (key == ESC)
		  destroy_window(data);
    ft_render(data);
    return (0);
}
