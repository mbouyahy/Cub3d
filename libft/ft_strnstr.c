/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz < jlaazouz@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:17:32 by jlaazouz          #+#    #+#             */
/*   Updated: 2022/11/20 23:14:29 by jlaazouz         ###   ########.fr       */
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

//search for the needle int the first len characters and return from it
// i + j < len --> we passed the len first char .