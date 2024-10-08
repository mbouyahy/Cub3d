/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:17:32 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/10/31 17:59:40 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*big;
	size_t	i;
	size_t	j;
	size_t	needle_len;

	big = (char *)haystack;
	needle_len = ft_strlen(needle);
	if (!needle_len)
		return (big);
	i = 0;
	while (big[i])
	{
		j = 0;
		while (big[i + j] == needle[j] && i + j < len)
		{
			j++;
			if (j == needle_len)
				return (big + i);
		}
		i++;
	}
	return (NULL);
}
