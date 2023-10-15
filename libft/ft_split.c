/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz < jlaazouz@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 01:34:50 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/03/29 22:07:15 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_words(const char *str, char c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	if (str[i] != c && str[i])
		size++;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1])
			size++;
		i++;
	}
	return (size);
}

char	*ft_fill(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		flag;
	size_t	i;
	size_t	j;

	split = malloc((ft_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (0);
	flag = -1;
	i = 0;
	j = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && flag < 0)
			flag = i;
		else if ((s[i] == c || i == ft_strlen(s)) && flag >= 0)
		{
			split[j++] = ft_fill(s, flag, i);
			flag = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

//