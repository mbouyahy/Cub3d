/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz < jlaazouz@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:47:05 by jlaazouz          #+#    #+#             */
/*   Updated: 2022/11/20 15:16:20 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;
	char	*dst;
	char	*srcs;

	dst = (char *)dest;
	srcs = (char *)src;
	if (!dst && !srcs)
		return ("");
	if (dst > srcs)
	{
		while (len > 0)
		{
			dst[len - 1] = srcs[len - 1];
			len--;
		}
	}
	else
	{
		i = -1;
		while (++i < len)
			dst[i] = srcs[i];
	}
	return (dst);
}
