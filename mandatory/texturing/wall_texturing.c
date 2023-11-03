/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_texturing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:10:31 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/11/01 20:47:09 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	draw_line_texture(t_data *data, mlx_texture_t *tex, int top, int bottom)
{
	int		window_y;
	float	inc;
	float	tex_y;
	float	x;

	x = data->texture.current_collumn;
	tex_y = 0;
	inc = (float)tex->height / (float)(bottom - top);
	window_y = top;
	if (top < 0)
	{
		window_y = 0;
		tex_y = (abs(top) * inc);
	}
	while (window_y < data->window_height)
	{
		if (x >= 0 && x < tex->width && tex_y >= 0 && tex_y < tex->height)
			data->texture.color = get_color_texture(tex, x, tex_y);
		if (data->var.i >= 0 && data->var.i < data->window_width
			&& window_y >= 0 && window_y < data->window_height)
			mlx_put_pixel(data->image, data->var.i, window_y,
				data->texture.color);
		tex_y += inc;
		window_y++;
	}
}

void	vertical_texturing(t_data *data, int top, int bottom)
{
	float	tmp;

	tmp = data->y_wall - ((int)(data->y_wall / data->cub)) * data->cub;
	if (cos(data->var.angle) >= 0)
	{
		data->texture.current_collumn = (data->ea->width * tmp) / data->tile;
		draw_line_texture(data, data->ea, top, bottom);
	}
	else if (cos(data->var.angle) < 0)
	{
		tmp = (data->we->width * tmp) / data->tile;
		data->texture.current_collumn = data->we->width - tmp;
		draw_line_texture(data, data->we, top, bottom);
	}
}

void	horizontal_texturing(t_data *data, int top, int bottom)
{
	float	tmp;

	tmp = data->x_wall - ((int)(data->x_wall / data->cub)) * data->cub;
	if (sin(data->var.angle) < 0)
	{
		data->texture.current_collumn = (data->no->width * tmp) / data->tile;
		draw_line_texture(data, data->no, top, bottom);
	}
	else if (sin(data->var.angle) >= 0)
	{
		tmp = (data->so->width * tmp) / data->tile;
		data->texture.current_collumn = data->so->width - tmp;
		draw_line_texture(data, data->so, top, bottom);
	}
}

void	texturing(t_data *data, int top, int bottom, int state)
{
	if (state == HORIZONTAL)
		horizontal_texturing(data, top, bottom);
	if (state == VERTICAL)
		vertical_texturing(data, top, bottom);
}

void	draw_scene_line(t_data *data, int top, int bottom, int axe)
{
	int	y;

	y = top;
	texturing(data, top, bottom, axe);
	y = 0;
	while (top >= 0 && y < top && top < data->window_height)
		if (data->var.i >= 0 && data->var.i < data->window_width && y >= 0
			&& y < data->window_height)
			mlx_put_pixel(data->image, data->var.i, y++,
				data->visuals->ceiling_color);
	y++;
	y = bottom;
	while (y >= 0 && y < data->window_height && bottom < data->window_height)
		if (data->var.i >= 0 && data->var.i < data->window_width && y >= 0
			&& y < data->window_height)
			mlx_put_pixel(data->image, data->var.i, y++,
				data->visuals->floor_color);
}
