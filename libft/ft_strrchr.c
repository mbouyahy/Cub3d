/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz < jlaazouz@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:44:26 by jlaazouz          #+#    #+#             */
/*   Updated: 2022/11/20 15:17:14 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	l;

	l = ft_strlen((char *)str);
	while (l >= 0)
	{
		if (str[l] == (char)c)
			return ((char *)str + l);
		l--;
	}
	return (NULL);
}
