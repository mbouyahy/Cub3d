/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:23:39 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/10/12 20:15:29 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	check_point_surrounding(t_data *cub, int i, int j)
{
	if (!(cub->map_grid[i][j + 1] == '0' || cub->map_grid[i][j + 1] == '1'
			|| cub->map_grid[i][j + 1] == 'N' || cub->map_grid[i][j + 1] == 'S'
			|| cub->map_grid[i][j + 1] == 'E' || cub->map_grid[i][j
			+ 1] == 'W'))
		return (ft_error(CLIFF_FOUND));
	else if (!(cub->map_grid[i][j - 1] == '0' || cub->map_grid[i][j - 1] == '1'
				|| cub->map_grid[i][j - 1] == 'N' || cub->map_grid[i][j
				- 1] == 'S' || cub->map_grid[i][j - 1] == 'E'
				|| cub->map_grid[i][j - 1] == 'W'))
		return (ft_error(CLIFF_FOUND));
	else if (!(cub->map_grid[i + 1][j] == '0' || cub->map_grid[i + 1][j] == '1'
				|| cub->map_grid[i + 1][j] == 'N' || cub->map_grid[i
				+ 1][1] == 'S' || cub->map_grid[i + 1][j] == 'E'
				|| cub->map_grid[i + 1][1] == 'W'))
		return (ft_error(CLIFF_FOUND));
	else if (!(cub->map_grid[i - 1][j] == '0' || cub->map_grid[i - 1][j] == '1'
				|| cub->map_grid[i - 1][j] == 'N' || cub->map_grid[i
				- 1][j] == 'S' || cub->map_grid[i - 1][j] == 'E'
				|| cub->map_grid[i - 1][j] == 'W'))
		return (ft_error(CLIFF_FOUND));
	return (EXIT_SUCCESS);
}

int	check_map_cliffs(t_data *cub)
{
	t_border	border;

	border.top = 1;
	border.buttom = ft_strlen_double_ptr(cub->map_grid) - 1;
	while (border.top < border.buttom)
	{
		border.right = ft_strlen(cub->map_grid[border.top]);
		border.left = 0;
		while (cub->map_grid[border.top][border.left]
			&& border.left < border.right)
		{
			if (border.left == 0
				&& cub->map_grid[border.top][border.left] == '0')
				return (ft_error(CLIFF_FOUND));
			else if (cub->map_grid[border.top][border.left] == '0')
				if (check_point_surrounding(cub, border.top, border.left))
					return (EXIT_FAILURE);
			border.left++;
		}
		border.top++;
	}
	return (EXIT_SUCCESS);
}

int	check_map_left_sides(char **map, int err)
{
	size_t	row;
	size_t	collom;
	size_t	len;

	row = 0;
	collom = 0;
	len = ft_strlen_double_ptr(map);
	while (row < len)
	{
		if (!(map[row][collom] == '1' || map[row][collom] == ' '))
			return (ft_error(err));
		row++;
	}
	return (EXIT_SUCCESS);
}

int	check_top_buttom_map(char **map, int row, int collom, int err)
{
	while (map[row][collom])
	{
		if (map[row][collom] == '1' || map[row][collom] == ' ')
			collom++;
		else
			return (ft_error(err));
	}
	return (EXIT_SUCCESS);
}

int	ft_check_valid_map(t_data *cub)
{
	int	i;

	i = 0;
	while (cub->map_grid[i])
	{
		if (!reached_set(cub->map_grid[i], MAP_SET_NEW))
			return (ft_error(EXTENTION_ERROR));
		i++;
	}
	return (0);
}
