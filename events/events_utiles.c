/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:08:47 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/25 19:28:08 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

float   deg_to_rad(float deg)
{
    return (deg * (M_PI / 180));   
}

int	destroy_window(t_data *data)
{
	//check leaks
    (void)data;
	exit(0);
}
