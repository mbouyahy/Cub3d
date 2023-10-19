/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:08:47 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/18 23:32:30 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

float   rad_to_deg(float rad)
{
    return (rad * (180 / M_PI));   
}

float   deg_to_rad(float deg)
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
