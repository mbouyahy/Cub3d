/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:08:47 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/15 19:09:20 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

float   deg_to_rad(int deg)
{
    return (deg * (M_PI / 180));   
}

float   deg_cos(int deg)
{
    return (deg_to_rad(deg));
}

float   deg_sin(int deg)
{
    return (deg_to_rad(deg));
}

int	destroy_window(t_data *data)
{
	//check leaks
    (void)data;
	exit(0);
}
