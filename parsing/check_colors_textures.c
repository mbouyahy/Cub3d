/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors_textures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:12:57 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/10/12 20:14:58 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	extract_color_code(t_data *cub)
{
	char	*key;
	char	*tmp;
	char	*color_code;
	int		i;

	i = 0;
	while (cub->visual_data[i])
	{
		key = ft_substr(cub->visual_data[i], 0, 1);
		tmp = ft_substr(cub->visual_data[i], 1, ft_strlen(cub->visual_data[i]));
		color_code = ft_strtrim(tmp, "\t ");
		if (!ft_strcmp(key, "F"))
			cub->visuals->floor_str = ft_strdup(color_code);
		else if (!ft_strcmp(key, "C"))
			cub->visuals->ceiling_str = ft_strdup(color_code);
		free(key);
		free(tmp);
		free(color_code);
		i++;
	}
	return (0);
}

int	extract_path(t_data *cub)
{
	char	*key;
	char	*tmp;
	char	*path;
	int		i;

	i = 0;
	while (cub->visual_data[i])
	{
		key = ft_substr(cub->visual_data[i], 0, 2);
		tmp = ft_substr(cub->visual_data[i], 2, ft_strlen(cub->visual_data[i]));
		path = ft_strtrim(tmp, "\t ");
		if (!ft_strcmp(cub->visual_data[i], "NO"))
			cub->visuals->no_texture = ft_strdup(path);
		else if (!ft_strcmp(key, "SO"))
			cub->visuals->so_texture = ft_strdup(path);
		else if (!ft_strcmp(key, "WE"))
			cub->visuals->we_texture = ft_strdup(path);
		else if (!ft_strcmp(key, "EA"))
			cub->visuals->ea_texture = ft_strdup(path);
		free(key);
		free(tmp);
		free(path);
		i++;
	}
	return (0);
}

int	check_double(t_data *cub)
{
	int	arr[6];
	int	i;

	i = 0;
	while (i < 6)
		arr[i++] = 0;
	ft_fill_doubles_array(arr, cub);
	while (i < 6)
	{
		if (arr[i] > 1)
			return (ft_error(VISUAL_DATA_ERR));
		i++;
	}
	return (0);
}

int	check_spacing_and_valid_components(t_data *cub)
{
	char	*tmp1;
	char	*tmp2;
	int		i;

	i = 0;
	while (cub->visual_data[i])
	{
		tmp1 = ft_substr(cub->visual_data[i], 0, 3);
		tmp2 = ft_substr(cub->visual_data[i], 0, 2);
		if (!ft_strcmp(tmp1, "NO ") || !ft_strcmp(tmp1, "SO ")
			|| !ft_strcmp(tmp1, "WE ") || !ft_strcmp(tmp1, "EA "))
			i++;
		else if (!ft_strcmp(tmp2, "F ") || !ft_strcmp(tmp2, "C "))
			i++;
		else
		{
			free(tmp1);
			free(tmp2);
			return (ft_error(BAD_TEXTURES_OR_COLORS_INFO));
		}
		free(tmp1);
		free(tmp2);
	}
	return (EXIT_SUCCESS);
}
