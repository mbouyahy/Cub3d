/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:02:20 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/09 22:19:15 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cup3d.h"
# include <mlx.h>
# include <fcntl.h>
#include "./Get_next_line/get_next_line.h"

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
void drow_sq(void *mlx_ptr, void *win_ptr, int x_start, int y_start, int color, int cup)
{
    int i = 0;
    int j = 0;
    x_start *= cup;
    y_start *= cup;
    while (j < cup)
    {
        while (i < cup)
        {
            mlx_pixel_put(mlx_ptr, win_ptr,x_start +  i,y_start + j, color);
            i++;
        }
        
        i = 0;
        j++;
    }
    
    
}

int main()
{
    // printf("DONE\n");
    void *mlx_ptr = NULL;
    void *win_ptr = NULL;
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 800, 400, "Mbouyahy");
    // img_ptr = mlx_new_image(win_ptr, 1000, 1000);
    // mlx_clear_window(mlx_ptr, win_ptr);
    list *map;
    map = fill_stock();
    // while (map)
    // {
    //     tmp = map->next;
    //     map->stock = ft_strtrim(map->stock, " ");//leaks
    //     printf("%s", map->stock);
    //     map = tmp;
    // }
    int x = 0;
    int y = 0;
    while (map)
    {
        while (map->stock[x])
        {
            if (map->stock[x] == '1')
                drow_sq(mlx_ptr, win_ptr, x, y, 0xffffff, 30);
            else if (map->stock[x] == '0')
                drow_sq(mlx_ptr, win_ptr, x, y, 4868967,30);
            else if (map->stock[x] == 'N')
            {
               printf("x = %d || y = %d\n", x, y); 
                drow_sq(mlx_ptr, win_ptr, x, y, 7878678,30);
            }
            x++;
        }
        map = map->next;
        y++;
        x = 0;
    }
    mlx_loop(mlx_ptr);
    // while (map)
    // {
    //     tmp = map->next;
    //     printf("%s", tmp->stock);
    //     // if (tmp->stock[0] && ft_strcmp(&tmp->stock[0], "1") == 0 && ft_strcmp(&tmp->stock[ft_strlen(tmp->stock)], "1") == 0)
    //         map = tmp;
    //     // else
    //     // {
    //     //     printf("Error");
    //     //     break ;
    //     // }
    // }
}