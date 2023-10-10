/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:26:10 by mbouyahy          #+#    #+#             */
/*   Updated: 2022/10/14 21:41:07 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*dest;

	j = 0;
	if (!s)
		return (NULL);
	if (start < ft_strlen(s))
	{
		if (len < ft_strlen(s))
		{
			dest = (char *)malloc(len + 1);
		}
		else
			dest = (char *)malloc(ft_strlen(s) - start + 1);
		if (dest != NULL)
			while (s[start] && j < len)
				dest[j++] = s[start++];
	}
	else
		dest = (char *)malloc(sizeof(char));
	if (!dest)
		return (NULL);
	dest[j] = '\0';
	return (dest);
}
