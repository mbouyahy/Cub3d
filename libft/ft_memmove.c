/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:30:09 by mbouyahy          #+#    #+#             */
/*   Updated: 2022/10/14 20:10:29 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dst_char;
	char	*src_char;

	i = 0;
	if (!dst && !src)
		return (NULL);
	dst_char = (char *)dst;
	src_char = (char *)src;
	if (src_char < dst_char)
	{
		while (len > 0)
		{
			dst_char[len - 1] = src_char[len - 1];
			len--;
		}
	}
	else
		ft_memcpy(dst_char, src_char, len);
	return (dst_char);
}
