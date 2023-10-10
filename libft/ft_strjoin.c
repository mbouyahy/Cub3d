/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:38:54 by mbouyahy          #+#    #+#             */
/*   Updated: 2022/10/14 21:45:56 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc(size + 1);
	if (new != NULL)
	{
		while (s1[i])
			new[j++] = s1[i++];
		i = 0;
		while (s2[i])
			new[j++] = s2[i++];
		new[j] = '\0';
	}
	else
		return (NULL);
	return (new);
}
