/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz < jlaazouz@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:32:48 by jlaazouz          #+#    #+#             */
/*   Updated: 2022/11/20 22:28:21 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	if (i <= len)
	{
		join = (char *)ft_calloc(len + 1, sizeof(char));
		if (!join)
			return (NULL);
		j = -1;
		while (s1[++j])
			join[i++] = s1[j];
		j = -1;
		while (s2[++j])
			join[i++] = s2[j];
		return (join);
	}
	return (NULL);
}
