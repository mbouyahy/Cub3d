/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:39:48 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/10/30 00:20:48 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int texture_checks(t_data   *data)
{
    data->no = mlx_load_png(data->visuals->no_texture);
    if (!data->no)
        return (ft_error(TEXTURE_OPENING));
    
    data->so = mlx_load_png(data->visuals->so_texture);
    if (!data->so)
        return (ft_error(TEXTURE_OPENING));

    data->we = mlx_load_png(data->visuals->we_texture);
    if (!data->we)
        return (ft_error(TEXTURE_OPENING));

    data->ea = mlx_load_png(data->visuals->ea_texture);
    if (!data->ea)
        return (ft_error(TEXTURE_OPENING));

    return (EXIT_SUCCESS);
}