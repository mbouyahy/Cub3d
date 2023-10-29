/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:39:44 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/10/29 16:06:02 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int mouse_move(int x, int y, t_data *data)
{
    (void)data;
    // data->mouse.old_x = x;
    // data->mouse.old_y = y;


    
    if (x > WINDOW_WIDTH)
        mlx_mouse_move(data->win_ptr, 0, y);

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
