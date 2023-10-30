/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:23:01 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/10/30 16:13:52 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void mouse(mouse_key_t button, action_t action, modifier_key_t mods, void* param)
{
	(void)button;
	(void)action;
	(void)mods;
	t_data *data = (t_data *)param;
	int32_t	x;
	int32_t	y;
	
	// mouse_mode
	mlx_get_mouse_pos(data->mlx, &x, &y);
	if (x >= 0 && x <= data->window_width && y >= 0 && y < data->window_height)
	{
		mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
		data->game_started = 1;
	}
	// else
	// 	mlx_set_mouse_pos(data->mlx, data->window_width/2 , data->window_height / 2);
		// mlx_mouse
		// mlx_is_mouse_down(data->mlx, button)	;	
	// printf ("x : %d\ny : %d\n", x, y);
	// if (mlx_is_mouse_down(data->mlx, MLX_MOUSE_BUTTON_RIGHT))
		// exit(0);
	// return (0);
}

void mouse_(void *param)
{
	t_data *data = (t_data *)param;
	int32_t	x;
	int32_t	y;
	
	mlx_get_mouse_pos(data->mlx, &x, &y);
	if (x >= 0 && x <= data->window_width && y >= 0 && y <= data->window_height)
	{
		if (data->new_x > x)
			rotate_line(data,  (-ROTATE * (M_PI / 180)));
		mlx_get_mouse_pos(data->mlx, &x, &y);
		if (data->new_x < x)
			rotate_line(data,  (+ROTATE * (M_PI / 180)));
		data->new_x = x;
		mlx_get_mouse_pos(data->mlx, &x, &y);
	}
	else if (x > data->window_width)
		mlx_set_mouse_pos(data->mlx, 0 , data->window_height / 2);
	else if (x < 0)
		mlx_set_mouse_pos(data->mlx, data->window_width , data->window_height / 2);
}

int	main(int ac, char **av)
{
	t_data  data;

	ft_init(&data);
	if (ft_map_checks(&data, ac, av[1]))
		return (EXIT_FAILURE);
    init_data(&data);
	if (texture_checks(&data))
		return(EXIT_FAILURE);

	data.mlx = mlx_init(data.window_width, data.window_height, "nice", false);
    data.image = mlx_new_image(data.mlx, data.window_width, data.window_height);
	mlx_image_to_window(data.mlx, data.image, 0, 0);

	mlx_loop_hook(data.mlx, ft_render, &data);
	mlx_loop_hook(data.mlx, key_events, &data);
	mlx_loop_hook(data.mlx, mouse_, &data);
	mlx_mouse_hook(data.mlx, mouse, &data);

    mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (0);
}
