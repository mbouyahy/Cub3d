/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:39:44 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/10/29 16:37:09 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int mouse_move(int x, int y, t_data *data)
{
    (void)data;
    (void)y;
    // data->mouse.old_x = x;
    // data->mouse.old_y = y;


    
    // if (x > WINDOW_WIDTH)
    //     mlx_mouse_move(data->win_ptr, 0, y);

    if (x > data->mouse.old_x)
    {
        rotate_line(data,  (2.1f * (M_PI / 180)));
        data->mouse.old_x = x;
    }
    else if (x < data->mouse.old_x)
    {
        rotate_line(data,  (-2.1f * (M_PI / 180)));
        data->mouse.old_x = x;
    }
    
    
    return (0);
}
