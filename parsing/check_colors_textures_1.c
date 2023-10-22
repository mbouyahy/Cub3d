/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors_textures_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:39:22 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/10/12 20:01:23 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	check_rgb_range(int r, int g, int b)
{
	if (r > 255 || g > 255 || b > 255)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	get_color(char *color_str, unsigned int *color)
{
	char	*r;
	char	*g;
	char	*b;
	int		i;

	r = color_str;
	g = r + ft_occurence_index(r, ',') + 1;
	b = g + ft_occurence_index(g, ',') + 1;
	i = -1;
	while (color_str[++i])
		if (color_str[i] == ',')
			color_str[i] = '\0';
	if (!str_isdigit(r) || !str_isdigit(g) || !str_isdigit(b))
		return (ft_error(COLOR_ALL_DIGITS));
	if (ft_strlen(r) == 0 || ft_strlen(g) == 0 || ft_strlen(b) == 0)
		return (ft_error(COLOR_FORMAT));
	if (ft_strlen(r) > 3 || ft_strlen(g) > 3 || ft_strlen(b) > 3)
		return (ft_error(COLOR_FORMAT));
	if (check_rgb_range(ft_atoi(r), ft_atoi(g), ft_atoi(b)))
		return (ft_error(COLOR_FORMAT));
	*color = create_trgb(0, ft_atoi(r), ft_atoi(g), ft_atoi(b));
	return (EXIT_SUCCESS);
}

int	get_floor_ceiling_color(t_data *cub)
{
	if (ft_occurence_time(cub->visuals->floor_str, ',') != 2)
		return (ft_error(COLOR_FORMAT));
	if (ft_occurence_time(cub->visuals->ceiling_str, ',') != 2)
		return (ft_error(COLOR_FORMAT));
	if (get_color(cub->visuals->floor_str, &cub->visuals->floor_color))
		return (EXIT_FAILURE);
	if (get_color(cub->visuals->ceiling_str, &cub->visuals->ceiling_color))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
