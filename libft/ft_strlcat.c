/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz < jlaazouz@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:47:12 by jlaazouz          #+#    #+#             */
/*   Updated: 2022/11/20 22:30:45 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t final_dst_size)
{
	size_t	len;
	size_t	src_len;
	size_t	i;

	len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (final_dst_size <= len)
		return (final_dst_size + src_len);
	i = 0;
	while (src[i] && len + i + 1 < final_dst_size)
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = 0;
	return (len + src_len);
}
