/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:06:14 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/11/01 22:46:20 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

int	store_necessary_info(t_data *cub, char *str)
{
	char		*tmp;
	size_t		len;
	static int	map_reached = 0;

	tmp = ft_strtrim(str, "\n");
	len = ft_strlen(tmp);
	if (len > cub->map_collums && map_reached)
		cub->map_collums = len + 1;
	if (map_reached && len == 0)
	{
		free(tmp);
		return (ft_error(EMPTY_LINE_ON_MAP));
	}
	if (!map_reached && reached_set(tmp, MAP_SET) && !is_whitespace(tmp))
	{
		map_reached = 1;
		cub->map_start = cub->file_len;
		cub->map_collums = len + 1;
	}
	cub->file = ft_join_ptr_to_double_ptr(cub->file, tmp);
	free(tmp);
	return (EXIT_SUCCESS);
}

int	ft_read_map(t_data *cub, char *map_name)
{
	int		map_fd;
	char	*str;

	map_fd = open(map_name, O_RDONLY);
	if (map_fd == -1)
		return (ft_error(FILE_PERMESIONS));
	str = get_next_line(map_fd);
	if (!str)
		return (ft_error(UNVALID_FILE));
	while (str)
	{
		if (store_necessary_info(cub, str))
		{
			free(str);
			return (EXIT_FAILURE);
		}
		cub->file_len++;
		free(str);
		str = get_next_line(map_fd);
	}
	cub->map_rows = cub->file_len - cub->map_start;
	free(str);
	close(map_fd);
	return (EXIT_SUCCESS);
}
