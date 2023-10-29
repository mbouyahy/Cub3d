/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:08:47 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/29 15:52:30 by jlaazouz         ###   ########.fr       */
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

void	ft_init(t_data *data)
{
	data->file = NULL;
	data->file_len = 0;
	data->map_rows  = 0;
	data->map_start = 0;
	data->visuals_len = 0;
	data->file_len = 0;
	data->map_collums  = 0;
	data->map_grid = NULL;
	data->visual_data = NULL;
	data->visuals = (t_visuals *)ft_calloc(1, sizeof(t_visuals));
    data->no.img_ptr = NULL;
    data->no.addr = NULL;
    data->so.img_ptr = NULL;
    data->so.addr = NULL;
    data->we.img_ptr = NULL;
    data->we.addr = NULL;
    data->ea.img_ptr = NULL;
    data->ea.addr = NULL;
    data->mouse.old_x = 0;
    data->mouse.old_y = 0;
    data->mouse.new_x = 0;
    data->mouse.new_y = 0;
}

void    init_data(t_data  *data)
{

    //data init
    data->angle = 0;
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
    // data->tile = data->cub - (int)((int)WINDOW_HEIGHT/(int)65);
    data->tile = data->cub;


    data->player.y = data->player.y * data->cub + (data->cub / 2);
    data->player.x = data->player.x * data->cub + (data->cub / 2);
    setup_angle(data);
}
