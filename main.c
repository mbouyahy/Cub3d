/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:02:20 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/12 19:12:41 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cup3d.h"

int main()
{
    t_data  data;

    init_data(&data);
    data.mlx_ptr = mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, data.width_size, data.height_size, "Mbouyahy");
    data.img.mlx_img = mlx_new_image(data.mlx_ptr, data.width_size, data.height_size);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, \
						&data.img.line_len, &data.img.endian);
    draw_map(&data);
    draw_line(&data);
    mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.mlx_img, 0, 0);
    mlx_hook(data.win_ptr, CLOSE_WIN, 0, &destroy_window, &data);
    mlx_key_hook(data.win_ptr, &player_moves, &data);
    mlx_loop(data.mlx_ptr);
}