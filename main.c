/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:02:20 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/10 19:06:23 by mbouyahy         ###   ########.fr       */
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
    t_data  data;

    // data = NULL;
    // data = (s_data *)malloc(sizeof(s_data *));
    // if (!data)
    //     exit(1);
    // data.mlx_ptr = NULL;
    // data.win_ptr = NULL;
    data.mlx_ptr = mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Mbouyahy");
    data.mlx_img = mlx_new_image(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data.addr = mlx_get_data_addr(data.mlx_img, &data.bpp, \
						&data.line_len, &data.endian);
    draw_map(&data);
    mlx_loop(data.mlx_ptr);
}