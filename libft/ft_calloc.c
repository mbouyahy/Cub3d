/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:57:18 by mbouyahy          #+#    #+#             */
/*   Updated: 2022/10/14 19:54:36 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*obj;

	obj = (char *)malloc(count * size);
	if (obj != NULL)
		ft_bzero(obj, size * count);
	return (obj);
}
