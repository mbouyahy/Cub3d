/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:27:55 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/10/10 15:02:28 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_extract_line(char *readed)
{
	char	*line;
	int		index;
	int		i;

	index = ft_index(readed);
	if (!readed)
		return (NULL);
	line = malloc((index + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (i < index)
	{
		line[i] = readed[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

char	*ft_left(char *readed)
{
	char	*left;
	size_t	index;
	size_t	i;

	index = ft_index(readed);
	if (index == ft_strlen_(readed))
	{
		free(readed);
		return (NULL);
	}
	left = malloc((ft_strlen_(readed) - index + 1) * sizeof(char));
	if (!left)
		return (NULL);
	i = 0;
	while (readed[index + i])
	{
		left[i] = readed[index + i];
		i++;
	}
	left[i] = 0;
	free(readed);
	return (left);
}

char	*get_next_line(int fd)
{
	static char	*readed[OPEN_MAX];
	char		buff[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	ret = 1;
	while (!ft_new_line_checker(readed[fd]))
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret < 1)
			break ;
		buff[ret] = 0;
		readed[fd] = ft_strjoin_(readed[fd], buff);
	}
	if (ret >= 0 && readed[fd])
		line = ft_extract_line(readed[fd]);
	readed[fd] = ft_left(readed[fd]);
	return (line);
}
