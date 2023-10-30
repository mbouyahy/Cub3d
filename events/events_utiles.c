/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:08:47 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/30 00:08:35 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

float   deg_to_rad(float deg)
{
    return (deg * (M_PI / 180));   
}

// int	destroy_window(t_data *data)
// {
// 	//check leaks
//     mlx_destroy_window(data->mlx_ptr, data->win_ptr);
// 	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
// 	exit(0);
// }
