/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:54:34 by mbouyahy          #+#    #+#             */
/*   Updated: 2022/11/13 17:30:26 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s)
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	len;

	if (!s || !c)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	while (i <= len && s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc(size + 1);
	if (new)
	{
		while (s1 && s1[i])
			new[j++] = s1[i++];
		i = 0;
		while (s2 && s2[i])
			new[j++] = s2[i++];
		new[j] = '\0';
	}
	return (new);
}

char	*lire_ligne(int fd, char *stock)
{
	char		*bufpart;
	char		*tmp;
	int			nread;

	bufpart = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!bufpart)
		return (NULL);
	nread = 1;
	while (nread != 0)
	{
		nread = read(fd, bufpart, BUFFER_SIZE);
		if (nread <= 0)
			break ;
		bufpart[nread] = '\0';
		tmp = stock;
		stock = ft_strjoin(tmp, bufpart);
		free(tmp);
		if (ft_strchr(bufpart, '\n'))
			break ;
	}
	free(bufpart);
	return (stock);
}
