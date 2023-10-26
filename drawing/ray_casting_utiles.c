/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_utiles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:30:23 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/26 17:17:56 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	find_coordinate(t_data *data, int value)
{
	if (value == HORIZONTAL)
	{
		//find coordinate BEGIN 
		//y coordinate
		data->dist._y = (int)(data->player.y / CUB_SIZE) * CUB_SIZE;
		if (data->ray_down)
			data->dist._y += CUB_SIZE;
		else
			data->dist._y +=0;//remove this

		//x coordinate
		data->dist._x = data->player.x + (data->dist._y - data->player.y) / tan(data->var.angle);
		//find coordinate END 
	}
	else if (value == VERTICAL)
	{
		//find coordinate BEGIN
		//X coordinate
		data->dist._x = (int)(data->player.x / CUB_SIZE) * CUB_SIZE;
		if (data->ray_right)
			data->dist._x += CUB_SIZE;
		else
			data->dist._x += 0;//remove this

		//Y coordinate
		data->dist._y = data->player.y + (data->dist._x - data->player.x) * tan(data->var.angle);
		//find coordinate END
	}
}

float	remainder_angle(float angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle +=  (2 * M_PI);
	return (angle);
}

void	horizontal_next_step(t_data *data)
{
	//find the next x and y steps BEGIN
	data->dist.y_step = CUB_SIZE;
	if (data->ray_up)
		data->dist.y_step *= -1;
	
	//x next step
	data->dist.x_step = CUB_SIZE / tan(data->var.angle);
	if (data->ray_left && data->dist.x_step > 0)
		data->dist.x_step *=-1;
	else if (data->ray_right && data->dist.x_step < 0)
		data->dist.x_step *=-1;
	//find the next x and y steps END
}

void	vertical_next_step(t_data *data)
{
	//find the next x and y steps BEGIN
	data->dist.x_step = CUB_SIZE;
	if (data->ray_left)
		data->dist.x_step *=-1;
	data->dist.y_step = CUB_SIZE * tan(data->var.angle);
	if (data->ray_up && data->dist.y_step > 0)
		data->dist.y_step *=-1;
	else if (data->ray_down && data->dist.y_step < 0)
		data->dist.y_step *= -1;
	//find the next x and y steps END

}

//check this function more or change it with clean code
int	is_inside_wall(t_data *data, float x, float y)
{
	int grid_x;
	int grid_y;

	grid_y = (int)(y / CUB_SIZE);
	grid_x = (int)(x / CUB_SIZE);
	if (grid_y >= WINDOW_HEIGHT / CUB_SIZE)//change this with rows and check it 
		return (TRUE);
	if (grid_y >= data->rows)//added
		return (TRUE);
	// printf("grid_y : %d\n", grid_y);
	if ((size_t)grid_x >= ft_strlen(data->map[grid_y]))//change this with cols and check it //SEGV
		return (TRUE);
	if (grid_x <= 0 || grid_y <= 0)//join this if statement with the first one and check if all thing work as you want
		return (TRUE);
	if (data->map[grid_y][grid_x] == '1')
		return (TRUE);
	return (FALSE);
}
