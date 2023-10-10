/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:08:37 by mbouyahy          #+#    #+#             */
/*   Updated: 2022/10/14 21:45:04 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nphrase(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
		{
			while (str[i] != c && str[i])
				i++;
		count++;
		}
	}
	return (count);
}

static int	ft_nchar(const char *str, char c, int j)
{
	int	count;

	count = 0;
	while (str[j] != c && str[j])
	{
		j++;
		count++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**str;
	int		x;

	x = 0;
	i = 0;
	str = (char **)malloc((ft_nphrase(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (i < ft_nphrase(s, c))
	{
		j = 0;
		while (s[x] == c)
			x++;
		str[i] = (char *)malloc(ft_nchar(s, c, x) + 1);
		if (!str[i])
			return (NULL);
		while (s[x] && s[x] != c)
			str[i][j++] = s[x++];
		str[i][j] = '\0';
		i++;
	}
	str[i] = NULL;
	return (str);
}
