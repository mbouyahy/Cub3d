/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:24:24 by mbouyahy          #+#    #+#             */
/*   Updated: 2022/10/14 21:36:55 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	j;

	j = 0;
	if (n == 0)
		return (0);
	while (s1[j] == s2[j] && s2[j] && s1[j] && j < n - 1)
	{
		j++;
	}
	return ((unsigned char)s1[j] - (unsigned char)s2[j]);
}
