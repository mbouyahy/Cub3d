/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:23:01 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/10/29 16:23:57 by jlaazouz         ###   ########.fr       */
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
	create_image(&data);
	if (texture_checks(&data))
		destroy_window(&data);

	mlx_loop_hook(data.mlx_ptr, ft_render, &data);//i deactivate this for testing some problems
    mlx_hook(data.win_ptr, KEY_PRESS, 0, key_events, &data);//2 for KeyPress and 3 for KeyRelease
    mlx_hook(data.win_ptr, CLOSE_WIN, 0, destroy_window, &data);
	// mlx_hook(data.win_ptr, 6, 1L << 6, &mouse_move, &data);
    mlx_loop(data.mlx_ptr);
	return (0);
}
