/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:08:47 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/26 22:17:17 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	create_image(t_data *data)
{
	data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Mbouyahy & Jlaazouz");
    data->img.mlx_img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, \
			&data->img.line_len, &data->img.endian);
}

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

void    init_data(t_data  *data)
{

    //data init
    data->map = data->map_grid;
    data->map_size = data->map_rows;
    data->x_start = 0;
    data->y_start = 0;
    data->cub = 20;
    data->fov = 60.0 * (M_PI / 180);
    data->collums = data->map_collums - 1;//fix this
    data->rows = data->map_rows;//fix this

    //minimap init
    data->minimap.height = WINDOW_HEIGHT / 3;
    data->minimap.width = WINDOW_WIDTH / 3;
    if (data->map_collums * data->cub > (WINDOW_WIDTH / 3))
        data->cub = (WINDOW_WIDTH / 3) / data->map_collums;
    if (data->map_rows * data->cub > (WINDOW_HEIGHT / 3))
        data->cub = (WINDOW_HEIGHT / 3) / data->map_rows - 1;

    //player init
    data->player.y = data->player.y * CUB_SIZE + (CUB_SIZE / 2);
    data->player.x = data->player.x * CUB_SIZE + (CUB_SIZE / 2);
    setup_angle(data);
}
