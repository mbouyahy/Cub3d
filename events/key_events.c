/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:12:24 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/19 11:27:32 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int key_events(int key, t_data *data)
{

    if (key == LEFT)
      data->var.rotate -= 0.1f;
    if (key == RIGHT)
      data->var.rotate += 0.1f;

    if (key == A)
    {
      data->var.move_x = data->var.move_x + cos((data->var.start_angle + data->var.rotate) - (M_PI / 2));
      data->var.move_y = data->var.move_y + sin((data->var.start_angle + data->var.rotate) - (M_PI / 2));
    }
    if (key == D)
    {
      data->var.move_x = data->var.move_x + cos((data->var.start_angle + data->var.rotate) + (M_PI / 2));
      data->var.move_y = data->var.move_y + sin((data->var.start_angle + data->var.rotate) + (M_PI / 2));
    }
    if (key == W)
    {
      data->var.move_x = data->var.move_x + cos((data->var.start_angle + data->var.rotate));
      data->var.move_y = data->var.move_y + sin((data->var.start_angle + data->var.rotate));
    }
    if (key == S)
    {
      data->var.move_x = data->var.move_x - cos((data->var.start_angle + data->var.rotate));
      data->var.move_y = data->var.move_y - sin((data->var.start_angle + data->var.rotate));
    }
    if (key == ESC)
		  destroy_window(data);
    return (0);
}
