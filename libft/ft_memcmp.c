/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:39:33 by mbouyahy          #+#    #+#             */
/*   Updated: 2022/10/13 19:36:59 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*a;
	char	*b;

	a = (char *)s1;
	b = (char *)s2;
	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (a[i] == b[i] && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)a[i] - (unsigned char)b[i]);
}
