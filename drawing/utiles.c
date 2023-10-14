/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:07:47 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/14 16:42:40 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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


int	find_coordinate(t_data *data, int next_point, int *step)
{
	//N => UP | S => DOWN
	if (data->player.p_direction == 'N' || data->player.p_direction == 'W')
	{
		*step = data->cub * -1;
		return ((int)roundf(next_point/data->cub) * data->cub - 1);//be rounded down | i removed -1
	}
	else if (data->player.p_direction == 'S' || data->player.p_direction == 'E')
	{
		*step = data->cub;
		return ((int)roundf(next_point/data->cub) * data->cub + data->cub);//be rounded down
	}
	return (0);
}

void	vertical_intersection(t_data *data)
{
	int	next_x = 0;
	int	next_y = 0;
	int y_step;
	int x_step;
	int	grid_x = 0;
	int	grid_y = 0;
	y_step = data->cub * tan(deg_to_rad(60));
	next_x = find_coordinate(data, data->player.x, &x_step);
	grid_x = (next_x / data->cub);
	next_y = data->player.y + ((data->player.x - next_x) * tan(deg_to_rad(60)));//
	grid_y = (next_y / data->cub);
	while (next_y < data->height_size && next_y >= 0 && next_x >= 0 && next_x < data->width_size)
	{
		printf("y = %d | next_y : %d | grid_y : %d\n", data->player.y, next_y, grid_y);
		printf("x = %d | next_x : %d | grid_x : %d\n", data->player.x, next_x, grid_x);
		printf("grid(%d,%d) : %c\n", grid_y, grid_x, data->map[grid_y][grid_x]);
		if (data->map[grid_y][grid_x] == '1')
		{
			printf("\nWALL\n\n");
			break ;
		}
		next_y += y_step;
		grid_y = (next_y / data->cub);
		next_x += x_step;
		grid_x = (next_x / data->cub);
	}
}

void	horizontal_intersection(t_data *data)
{
	int	next_x = 0;
	int	next_y = 0;
	int y_step;
	int x_step;
	int	grid_x = 0;
	int	grid_y = 0;
	x_step = data->cub / tan(deg_to_rad(60));
	next_y = find_coordinate(data, data->player.y, &y_step);
	grid_y = (next_y / data->cub);
	next_x = data->player.x + ((data->player.y - next_y) / tan(deg_to_rad(60)));
	grid_x = (next_x / data->cub);
	while (next_y < data->height_size && next_y >= 0 && next_x >= 0 && next_x < data->width_size)
	{
		printf("y = %d | next_y : %d | grid_y : %d\n", data->player.y, next_y, grid_y);
		printf("x = %d | next_x : %d | grid_x : %d\n", data->player.x, next_x, grid_x);
		printf("grid(%d,%d) : %c\n", grid_y, grid_x, data->map[grid_y][grid_x]);
		if (data->map[grid_y][grid_x] == '1')
		{
			printf("\nWALL\n\n");
			break ;
		}
		next_y += y_step;
		grid_y = (next_y / data->cub);
		next_x += x_step;
		grid_x = (next_x / data->cub);
	}
}
