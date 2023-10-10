/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:02:20 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/10 16:49:35 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cup3d.h"

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

int main()
{
    // void    *mlx_ptr;
    // void    *win_ptr;
    s_data  data;

    // data = NULL;
    // data = (s_data *)malloc(sizeof(s_data *));
    // if (!data)
    //     exit(1);
    data.mlx_ptr = NULL;
    data.win_ptr = NULL;
    data.mlx_ptr = mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 400, "Mbouyahy");
    // img_ptr = mlx_new_image(win_ptr, 1000, 1000);
    // mlx_clear_window(mlx_ptr, win_ptr);
    draw_map(&data);
    mlx_loop(data.mlx_ptr);
}