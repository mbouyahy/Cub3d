/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:20:25 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/10/13 12:37:39 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	ft_check_visuals_data(t_data *cub)
{
	if (ft_strlen_double_ptr(cub->visual_data) != 6)
		return (ft_error(VISUAL_DATA_ERR));
	if (check_spacing_and_valid_components(cub))
		return (EXIT_FAILURE);
	if (check_double(cub))
		return (EXIT_FAILURE);
	if (extract_path(cub))
		return (EXIT_FAILURE);
	if (extract_color_code(cub))
		return (EXIT_FAILURE);
	if (get_floor_ceiling_color(cub))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_check_map_data(t_data *cub)
{
	if (ft_check_valid_map(cub))
		return (EXIT_FAILURE);
	if (ft_more_than_one_player(cub))
		return (EXIT_FAILURE);
	if (check_player_surrounding(cub))
		return (EXIT_FAILURE);
	if (check_top_buttom_map(cub->map_grid, 0, 0, TOP_MAP_ERR))
		return (EXIT_FAILURE);
	if (check_top_buttom_map(cub->map_grid, ft_strlen_double_ptr(cub->map_grid)
			- 1, 0, BUTTOM_MAP_ERR))
		return (EXIT_FAILURE);
	if (check_map_cliffs(cub))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_check_map_name(char *str)
{
	char	*extention;

	extention = ft_strrchr(str, '.');
	if (!extention)
		return (ft_error(EXTENTION_ERROR));
	if (!ft_strcmp(extention, ".cub"))
		return (EXIT_SUCCESS);
	else
		return (ft_error(EXTENTION_ERROR));
	return (EXIT_SUCCESS);
}

int	ft_map_parsing(t_data *cub, char *map_name)
{
	if (ft_read_map(cub, map_name))
		return (EXIT_FAILURE);
	if (fill_visual_data(cub))
		return (EXIT_FAILURE);
	if (fill_map_data(cub))
		return (EXIT_FAILURE);
	if (ft_check_visuals_data(cub))
		return (EXIT_FAILURE);
	if (ft_check_map_data(cub))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_map_checks(t_data *cub, int ac, char *map_name)
{
	if (ac != 2)
		return (ft_error(BAD_ARG));
	if (ft_check_map_name(map_name))
		return (EXIT_FAILURE);
	if (ft_map_parsing(cub, map_name))
	{
		printf("BAD MAP\n");
		return (EXIT_FAILURE);
	}
	else
		printf("GOOD MAP\n");
	printf("x : %d\n", cub->player.x);
	printf("y : %d\n", cub->player.y);
	return (EXIT_SUCCESS);
}
