/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz < jlaazouz@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:29:23 by jlaazouz          #+#    #+#             */
/*   Updated: 2022/11/20 15:16:17 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		((char *)dest)[i] = str[i];
		i++;
	}
	return (dest);
}
