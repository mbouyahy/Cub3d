/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz < jlaazouz@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:27:51 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/04/11 19:48:18 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_new_line_checker(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (1);
	return (0);
}

int	ft_index(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin_(char *readed, char *buff)
{
	char	*join;
	int		i;
	int		j;

	join = malloc((ft_strlen_(readed) + ft_strlen_(buff) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	if (readed)
	{
		while (readed[i])
		{
			join[i] = readed[i];
			i++;
		}
	}
	j = -1;
	while (buff[++j])
		join[i + j] = buff[j];
	join[i + j] = 0;
	free(readed);
	return (join);
}
