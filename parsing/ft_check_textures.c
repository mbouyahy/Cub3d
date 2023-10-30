/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:39:48 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/10/29 15:10:19 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int ft_open_textures(t_data *data)
{
    data->no.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, data->visuals->no_texture,
                    &data->no.width, &data->no.height);
    if (!data->no.img_ptr)
        return (ft_error(TEXTURE_OPENING));
    data->so.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, data->visuals->so_texture,
                    &data->so.width, &data->so.height);
    if (!data->so.img_ptr)
        return (ft_error(TEXTURE_OPENING));
    data->ea.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, data->visuals->ea_texture,
                    &data->ea.width, &data->ea.height);
    if (!data->ea.img_ptr)
        return (ft_error(TEXTURE_OPENING));
    data->we.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, data->visuals->we_texture,
                    &data->we.width, &data->we.height);
    if (!data->we.img_ptr)
        return (ft_error(TEXTURE_OPENING));
    return (EXIT_SUCCESS);
}

int  ft_allocate_images(t_data *data)
{
    data->no.addr = mlx_get_data_addr(data->no.img_ptr, &data->no.bpp, &data->no.line_len, &data->no.endian);
    if (!data->no.addr)
        return (ft_error(IMAGE_ALLOCATION));
    data->so.addr = mlx_get_data_addr(data->so.img_ptr, &data->so.bpp, &data->so.line_len, &data->so.endian);
    if (!data->so.addr)
        return (ft_error(IMAGE_ALLOCATION));
    data->ea.addr = mlx_get_data_addr(data->ea.img_ptr, &data->ea.bpp, &data->ea.line_len, &data->ea.endian);
    if (!data->ea.addr)
        return (ft_error(IMAGE_ALLOCATION));
    data->we.addr = mlx_get_data_addr(data->we.img_ptr, &data->we.bpp, &data->we.line_len, &data->we.endian);
    if (!data->we.addr)
        return (ft_error(IMAGE_ALLOCATION));
    return (EXIT_SUCCESS);
}

int texture_checks(t_data   *data)
{
    if (ft_open_textures(data))
        return (EXIT_FAILURE);
    if (ft_allocate_images(data))
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}