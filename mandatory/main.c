/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:23:01 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/11/01 19:31:42 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (0);
}
