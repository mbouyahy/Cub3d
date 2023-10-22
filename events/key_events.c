/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:12:24 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/22 17:18:38 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int stop_move(t_data *data, float x, float y)
{
  int grid_x;
  int grid_y;
  
  grid_x = x / data->cub;
  grid_y = y / data->cub;
  
  if (data->map[grid_y][grid_x] == '1')
    return (1);
  return(0);
} 

// void  activate_moves(t_data *data)
// {
//   data->var.rotate += data->player.t_dir * data->player.r_speed;
  
//   float step = data->player.w_dir * 2.0;
  
//   data->var.move_x += cos(data->var.rotate) * step; 
//   data->var.move_y += sin(data->var.rotate) * step; 
// }

int	ft_render(t_data *data)
{
  // redraw(data, 1);
  // activate_moves(data);
  // data->player.t_dir = 0;
  // data->player.w_dir = 0;
  draw_map(data, 0);
  draw_line(data);
	// change_view(data);
    // player_moves(data);
  mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}


// int key_events(int key, t_data *data)
// {
//     // if (key == LEFT)
//     //   data->var.rotate -= 0.1f;
//     // if (key == RIGHT)
//     //   data->var.rotate += 0.1f;
//     if (key == A)
//     {
//       data->player.w_dir = -1;
//     }
//     if (key == D)
//     {
//       data->player.w_dir = 1;
//     }
//     if (key == W)
//     {
//       data->player.t_dir = 1;
//     }
//     if (key == S)
//     {
//       data->player.t_dir = -1;
//     }
//     if (key == ESC)
// 		  destroy_window(data);
//     // ft_render(data);
//     return (0);
// }

int key_events(int key, t_data *data)
{
    if (key == LEFT)
      data->var.rotate -= 0.1f;
    if (key == RIGHT)
      data->var.rotate += 0.1f;
    if (key == A)
    {
      data->var.move_x += cos((data->var.start_angle + data->var.rotate) - (M_PI / 2));
      data->var.move_y += sin((data->var.start_angle + data->var.rotate) - (M_PI / 2));
    }
    if (key == D)
    {
      data->var.move_x += cos((data->var.start_angle + data->var.rotate) + (M_PI / 2));
      data->var.move_y += sin((data->var.start_angle + data->var.rotate) + (M_PI / 2));
    }
    if (key == W)
    {
      data->var.move_x += cos((data->var.start_angle + data->var.rotate));
      data->var.move_y += sin((data->var.start_angle + data->var.rotate));
    }
    if (key == S)
    {
      data->var.move_x -= cos((data->var.start_angle + data->var.rotate));
      data->var.move_y -= sin((data->var.start_angle + data->var.rotate));
    }
    if (key == ESC)
		  destroy_window(data);
    // ft_render(data);
    return (0);
}

