/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:02:20 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/11 21:07:52 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cup3d.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	j;

	j = 0;
	while (s1[j] == s2[j] && s2[j] && s1[j])
	{
		j++;
	}
	return (s1[j] - s2[j]);
}


void    init_data(t_data  *data)
{
    //gamer init
    data->gamer.pos_x = 0;
    data->gamer.pos_y = 0;
    data->gamer.rad = 3;
    data->gamer.t_dir = 0;
    data->gamer.w_dir = 0;
    data->gamer.r_angle = M_PI / 2;
    data->gamer.r_speed = 50 * (M_PI / 180);
    data->gamer.m_speed = 100;//convert it to float


    data->map = fill_array(&data->map_size);
    data->x_start = 0;
    data->y_start = 0;
    data->cup = 60;
    data->width_size = (ft_strlen(data->map[0]) - 1) * data->cup;
    if (data->map && data->map[0])
        data->height_size = data->map_size * data->cup;
}

void    draw_line(t_data *data)
{
    int x;
    int y;
    int x_end;
    int y_end;

    x = data->gamer.pos_x + data->cup;
    y = data->gamer.pos_y + data->cup;
    x_end = (x + cos(data->gamer.r_angle)) * 10;
    y_end = (y + sin(data->gamer.r_angle)) * 10;
    // printf("r_angle = %f || x = %d || x_end = %d \n y = %d || y_end = %d \n", data->gamer.r_angle, x, x_end, y, y_end);
    while (x < x_end)
    {   
        while (y < y_end)
        {
            put_img(y, x, 0xFF0000, data);
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->mlx_img, 0, 0);
}

int player_moves(int btr, t_data *data)
{
    if (btr == UP)
    {
        data->gamer.w_dir = 1;
        data->gamer.r_angle += data->gamer.w_dir * data->gamer.r_speed;
        // printf("w_dir = %d\n", data->gamer.w_dir);
    }
    else if (btr == DOWN)
    {
        data->gamer.w_dir = -1;
        data->gamer.r_angle += data->gamer.w_dir * data->gamer.r_speed;
    }
    else if (btr == LEFT)
    {
        data->gamer.t_dir = 1;
        data->gamer.r_angle += data->gamer.t_dir * data->gamer.r_speed;
    }
    else if (btr == RIGHT)
    {
        data->gamer.t_dir = -1;
        data->gamer.r_angle += data->gamer.t_dir * data->gamer.r_speed;
    }
    // mlx_clear_window(data->mlx_ptr, data->win_ptr);
    mlx_destroy_image(data->mlx_ptr, data->mlx_img);
    data->mlx_img = mlx_new_image(data->mlx_ptr, data->width_size, data->height_size);
	data->addr = mlx_get_data_addr(data->mlx_img, &data->bpp, \
						&data->line_len, &data->endian);
    draw_map(data);
    draw_line(data);
    // printf("x_start = %d, y_start = %d\n, x_pos = %d, y_pos = %d\n", data->x_start, data->y_start, data->gamer.pos_x, data->gamer.pos_y);
    data->gamer.t_dir = 0;
    data->gamer.w_dir = 0;
    // mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->mlx_img, 0, 0);
    return (0);
}

int main()
{
    t_data  data;

    init_data(&data);
    data.mlx_ptr = mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, data.width_size, data.height_size, "Mbouyahy");
    data.mlx_img = mlx_new_image(data.mlx_ptr, data.width_size, data.height_size);
	data.addr = mlx_get_data_addr(data.mlx_img, &data.bpp, \
						&data.line_len, &data.endian);
    draw_map(&data);
    draw_line(&data);
    mlx_key_hook(data.win_ptr, &player_moves, &data);
    mlx_loop(data.mlx_ptr);
}