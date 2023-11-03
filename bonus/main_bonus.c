/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:23:01 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/11/01 20:55:29 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_bonus.h"

void	free_double(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	free_data(t_data *data)
{
	free_double(data->map_grid);
	free(data->visuals->no_texture);
	free(data->visuals->so_texture);
	free(data->visuals->we_texture);
	free(data->visuals->ea_texture);
	free(data->visuals);
	mlx_delete_texture(data->no);
	mlx_delete_texture(data->so);
	mlx_delete_texture(data->ea);
	mlx_delete_texture(data->we);
	mlx_delete_image(data->mlx, data->image);
}

void	mouse(mouse_key_t button, action_t action, modifier_key_t mods,
		void *param)
{
	t_data	*data;
	int32_t	x;
	int32_t	y;

	(void)button;
	(void)action;
	(void)mods;
	data = (t_data *)param;
	mlx_get_mouse_pos(data->mlx, &x, &y);
	if (x >= 0 && x <= data->window_width && y >= 0 && y < data->window_height)
	{
		mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
		data->game_started = 1;
	}
}

void	mouse_(void *param)
{
	t_data	*data;
	int32_t	x;
	int32_t	y;

	data = (t_data *)param;
	mlx_get_mouse_pos(data->mlx, &x, &y);
	if (x >= 0 && x <= data->window_width && y >= 0 && y <= data->window_height)
	{
		if (data->new_x > x)
			rotate_line(data, (-ROTATE * (M_PI / 180)));
		mlx_get_mouse_pos(data->mlx, &x, &y);
		if (data->new_x < x)
			rotate_line(data, (+ROTATE * (M_PI / 180)));
		data->new_x = x;
		mlx_get_mouse_pos(data->mlx, &x, &y);
	}
	else if (x > data->window_width)
		mlx_set_mouse_pos(data->mlx, 0, data->window_height / 2);
	else if (x < 0)
		mlx_set_mouse_pos(data->mlx, data->window_width,
			data->window_height / 2);
}

int	main(int ac, char **av)
{
	t_data	data;

	ft_init(&data);
	if (ft_map_checks(&data, ac, av[1]))
		return (EXIT_FAILURE);
	init_data(&data);
	if (texture_checks(&data))
		return (EXIT_FAILURE);
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
