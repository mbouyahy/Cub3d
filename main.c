/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:23:01 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/10/18 22:01:20 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_init(t_data *cub)
{
	cub->file = NULL;
	cub->file_len = 0;
	cub->map_rows  = 0;
	cub->map_start = 0;
	cub->visuals_len = 0;
	cub->file_len = 0;
	cub->map_collums  = 0;
	cub->map_grid = NULL;
	cub->visual_data = NULL;
	cub->visuals = (t_visuals *)ft_calloc(1, sizeof(t_visuals));
}

int	main(int ac, char **av)
{
	t_data  data;

	ft_init(&data);
	if (ft_map_checks(&data, ac, av[1]))
		return (EXIT_FAILURE);

    init_data(&data);
    data.mlx_ptr = mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Mbouyahy & Jlaazouz");
    data.img.mlx_img = mlx_new_image(data.mlx_ptr, data.width_size, data.height_size);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, \
						&data.img.line_len, &data.img.endian);
    draw_map(&data, 0);
    draw_line(&data);
    mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.mlx_img, 0, 0);
    mlx_hook(data.win_ptr, CLOSE_WIN, 0, destroy_window, &data);
    mlx_hook(data.win_ptr, KEY_PRESS, 0, key_events, &data);//2 for KeyPress and 3 for KeyRelease
    mlx_loop(data.mlx_ptr);
	// system("leaks cub");   
	return (0);
}
