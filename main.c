/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:23:01 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/10/21 13:06:26 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int ac, char **av)
{
	t_data  data;

	ft_init(&data);
	if (ft_map_checks(&data, ac, av[1]))
		return (EXIT_FAILURE);

    init_data(&data);
    data.mlx_ptr = mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, data.width_size, data.height_size, "Mbouyahy & Jlaazouz");
    data.img.mlx_img = mlx_new_image(data.mlx_ptr, data.width_size, data.height_size);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, \
						&data.img.line_len, &data.img.endian);
	mlx_loop_hook(data.mlx_ptr, ft_render, &data);
    mlx_hook(data.win_ptr, CLOSE_WIN, 0, destroy_window, &data);
    mlx_hook(data.win_ptr, KEY_PRESS, 0, key_events, &data);//2 for KeyPress and 3 for KeyRelease
    mlx_loop(data.mlx_ptr);
	return (0);
}
