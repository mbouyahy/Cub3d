/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_textures_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:39:48 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/11/01 22:46:20 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

int	texture_checks(t_data *data)
{
	data->no = mlx_load_png(data->visuals->no_texture);
	if (!data->no)
		return (ft_error(TEXTURE_OPENING));
	data->so = mlx_load_png(data->visuals->so_texture);
	if (!data->so)
	{
		mlx_delete_texture(data->no);
		return (ft_error(TEXTURE_OPENING));
	}
	data->we = mlx_load_png(data->visuals->we_texture);
	if (!data->we)
	{
		mlx_delete_texture(data->no);
		mlx_delete_texture(data->so);
		return (ft_error(TEXTURE_OPENING));
	}
	data->ea = mlx_load_png(data->visuals->ea_texture);
	if (!data->ea)
	{
		mlx_delete_texture(data->no);
		mlx_delete_texture(data->so);
		mlx_delete_texture(data->we);
		return (ft_error(TEXTURE_OPENING));
	}
	return (EXIT_SUCCESS);
}
