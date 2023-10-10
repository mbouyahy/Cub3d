/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:10:22 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/10 19:58:21 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cup3d.h"

int	map_size()
{    
	int fd;
    int map_size;
    char *stock;

	map_size = 0;
	fd = open("maps", O_RDWR, 777);//convert it to READ ONLY!
	stock = get_next_line(fd);
    while (stock != NULL)
    {
        stock = get_next_line(fd);
		map_size++;
    }
	return (map_size);
}

char	**fill_stock(int *map_s)
{
    char	*stock;
    char	**map;
	int		fd;
	int		i;
	int		size;

	i = 0;
	size = map_size();
	*map_s = size;
	map = malloc(sizeof(char **) * size);
	if (!map)
		exit(1);//test

	fd = open("maps", O_RDWR, 777);//convert it to READ ONLY!
	stock = get_next_line(fd);
	while (i < size)
	{
		map[i] = malloc(sizeof(char *) * ft_strlen(stock));
		if (!map[i])
			exit(1);//test
		map[i] = stock;
		stock = get_next_line(fd);
		i++;
	}
    close(fd);
    return (map);
}

void draw_sq(t_data *data, int color, int cup)
{
    int i = 0;
    int j = 0;

    data->x_start *= cup;
    data->y_start *= cup;
    while (j < cup)
    {
        while (i < cup)
        {
            if (data->x_start + i < WIN_WIDTH && data->y_start + j < WIN_HEIGHT)
                put_img(data->x_start + i, data->y_start + j, color, data);
            printf("data->x_start + i = %d, data->y_start + j = %d\n", data->x_start + i, data->y_start + j);
            i++;
        }
        i = 0;
        j++;
    }
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->mlx_img, 0, 0);
}

void    draw_map(t_data *data)
{
    char **map;
    int map_size;
    int x;
    int y;

    x = 0;
    y = 0;
    map_size = 0;
    map = fill_stock(&map_size);
    while (y < map_size)
    {
        while (map[y][x])
        {
			data->x_start = x;
			data->y_start = y;
            if (map[y][x] == '1')
                draw_sq(data, 0xffffff, 30);
            else if (map[y][x] == '0')
                draw_sq(data, 4868967,30);
            else if (map[y][x] == 'N')
            {
                draw_sq(data, 7878678,30);//test
            }
            x++;
        }
        y++;
        x = 0;
    }
}
