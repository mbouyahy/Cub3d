/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:10:22 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/13 11:44:43 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	map_size()
{    
	int fd;
    int map_size;
    char *stock;

	map_size = 0;
	fd = open("maps", O_RDONLY, 777);//convert it to READ ONLY!
	stock = get_next_line(fd);
    while (stock != NULL)
    {
        stock = get_next_line(fd);
		map_size++;
    }
	return (map_size);
}

char	**fill_array(int *map_s)
{
    char	*stock;
    char	**map;
	int		size;
	int		fd;
	int		i;

	i = 0;
	size = map_size();
	*map_s = size;
	//don't forget to check fd
	fd = open("maps", O_RDONLY, 777);//convert it to READ ONLY!
	map = malloc(sizeof(char **) * size);
	if (!map)
		exit(1);//test
	stock = get_next_line(fd);
	while (i < size)
	{
		map[i] = malloc(sizeof(char *) * ft_strlen(stock));
		if (!map[i])
			exit(1);//test
		map[i] = stock;
		stock = get_next_line(fd);
		i++;
	}
    close(fd);
    return (map);
}
