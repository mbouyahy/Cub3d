/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz < jlaazouz@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:01:28 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/04/11 18:44:43 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*subs;

	s_len = ft_strlen(s);
	if (len > start + s_len)
		len = s_len - start + 1;
	if (start >= s_len)
	{
		subs = malloc(1);
		subs[0] = 0;
		return (subs);
	}
	subs = (char *)malloc(len + 1);
	if (!s || !subs)
		return (NULL);
	i = 0;
	while (start + i < start + len && *s)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = 0;
	return (subs);
}
