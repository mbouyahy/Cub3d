/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:10:54 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/10/12 20:19:44 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	str_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen_double_ptr(char **c)
{
	int	i;

	i = 0;
	if (!c)
		return (i);
	while (c[i])
		i++;
	return (i);
}

void	free_double_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i++] = NULL;
	}
	free(str);
	str = NULL;
}

char	**ft_join_ptr_to_double_ptr(char **arr1, char *str)
{
	int		len;
	int		i;
	char	**joined;

	len = ft_strlen_double_ptr(arr1);
	joined = (char **)ft_calloc(sizeof(char *), len + 4);
	i = 0;
	if (arr1)
	{
		while (arr1[i])
		{
			joined[i] = ft_strdup(arr1[i]);
			i++;
		}
		free_double_array(arr1);
	}
	joined[i] = ft_strdup(str);
	return (joined);
}
