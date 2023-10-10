/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 09:57:20 by mbouyahy          #+#    #+#             */
/*   Updated: 2022/10/14 21:40:40 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	verifier(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	firstset(const char	*s1, const char *set)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s1[i])
	{
		if (verifier(set, s1[i]) == 1)
		{
			i++;
			count++;
		}
		else
			return (count);
	}
	return (count);
}

static int	lastset(const char	*s1, const char *set)
{
	int	i;
	int	count;

	i = ft_strlen(s1) - 1;
	count = 0;
	while (i >= 0 && s1[i])
	{
		if (verifier(set, s1[i]) == 1)
		{
			i--;
			count++;
		}
		else
			return (count);
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		size;
	char	*res;
	int		j;
	int		x;

	x = 0;
	if (!s1 || !set)
		return (NULL);
	i = firstset(s1, set);
	j = lastset(s1, set);
	if (i == j && j == (int)ft_strlen(s1))
		res = (char *)malloc(1);
	else
	{
		size = ft_strlen(s1) - i - j;
		res = (char *)malloc(size + 1);
		if (!res)
			return (NULL);
		size = ft_strlen(s1);
		while (s1[i] && i < size - j)
			res[x++] = s1[i++];
	}
	res[x] = '\0';
	return (res);
}
