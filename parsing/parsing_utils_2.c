/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:22:10 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/10/12 20:20:02 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ft_fill_doubles_array(int *arr, t_data *cub)
{
	int	i;

	i = -1;
	while (cub->visual_data[++i])
	{
		if (!ft_strncmp(cub->visual_data[i], "NO", 2))
			arr[NO]++;
		else if (!ft_strncmp(cub->visual_data[i], "SO", 2))
			arr[SO]++;
		else if (!ft_strncmp(cub->visual_data[i], "EA", 2))
			arr[EA]++;
		else if (!ft_strncmp(cub->visual_data[i], "WE", 2))
			arr[WE]++;
		else if (!ft_strncmp(cub->visual_data[i], "F ", 2))
			arr[F]++;
		else if (!ft_strncmp(cub->visual_data[i], "C ", 2))
			arr[C]++;
	}
}

int	reached_set(char *str, char *set)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr(set, str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_occurence_time(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	ft_occurence_index(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str && str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
