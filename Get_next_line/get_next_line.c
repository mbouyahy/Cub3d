/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:55:17 by mbouyahy          #+#    #+#             */
/*   Updated: 2022/11/12 16:40:22 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_vider(char *stock)
{
	int		i;
	int		j;
	int		len;
	char	*reste;

	i = 0;
	j = 0;
	len = ft_strlen(stock);
	while (i < len && stock[i])
	{
		if (stock[i] && stock[i] == '\n' && stock[i + 1] != '\0')
		{
			reste = (char *)malloc(len - i);
			if (!reste)
				return (NULL);
			i++;
			while (i <= len && stock[i])
				reste[j++] = stock[i++];
			reste[j] = '\0';
			return (reste);
		}
		i++;
	}
	return (NULL);
}

char	*ft_ligne(char *stock)
{
	char	*ligne;
	int		i;
	int		count;

	count = 0;
	i = 0;
	if (!stock[0])
		return (NULL);
	while (stock[count] && stock[count] != '\n')
		count++;
	ligne = malloc((count + 2) * sizeof(char));
	if (!ligne)
		return (NULL);
	while (stock[i] && stock[i] != '\n')
	{
		ligne[i] = stock[i];
		i++;
	}
	if (stock[i] == '\n')
		ligne[i++] = '\n';
	ligne[i] = '\0';
	return (ligne);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*ligne;
	char		*tmp;

	if (fd < 0 || fd == 2 || fd == 1 || BUFFER_SIZE <= 0)
		return (NULL);
	stock = lire_ligne(fd, stock);
	if (!stock)
		return (NULL);
	tmp = stock;
	ligne = ft_ligne(tmp);
	stock = ft_vider(tmp);
	free(tmp);
	return (ligne);
}
