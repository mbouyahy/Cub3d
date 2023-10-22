/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:07:29 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/10/13 15:10:34 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	fill_map_data(t_data *cub)
{
	size_t	i;
	size_t	j;

	cub->map_grid = (char **)ft_calloc(cub->map_rows  + 1, sizeof(char *));
	i = cub->map_start;
	j = 0;
	while (i < cub->file_len)
	{
		if (!is_whitespace(cub->file[i]))
		{
			cub->map_grid[j] = (char *)malloc(cub->map_collums  + 1 * sizeof(char));
			cub->map_grid[j][cub->map_collums ] = 0;
			ft_memset(cub->map_grid[j], ' ', cub->map_collums );
			ft_memcpy(cub->map_grid[j], cub->file[i], ft_strlen(cub->file[i]));
		}
		else
		{
			cub->map_grid[j] = (char *)malloc(cub->map_collums  + 1 * sizeof(char));
			cub->map_grid[j][cub->map_collums ] = 0;
			ft_memset(cub->map_grid[j], ' ', cub->map_collums );
		}
		j++;
		i++;
	}
	return (EXIT_SUCCESS);
}

int	fill_visual_data(t_data *cub)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (i < cub->map_start)
	{
		if (!reached_set(cub->file[i], MAP_SET))
		{
			tmp = ft_strtrim(cub->file[i], " ");
			free(cub->file[i]);
			cub->file[i] = tmp;
			cub->visual_data = ft_join_ptr_to_double_ptr(cub->visual_data,
					cub->file[i]);
		}
		i++;
	}
	return (0);
}
