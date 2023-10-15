/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexacount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz < jlaazouz@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:02:02 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/03/23 14:45:47 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexacount(unsigned int n)
{
	if ((n > 15) == 0)
		return (1);
	return (1 + ft_hexacount(n / 16));
}

int	ft_putnbr_base_hex(unsigned int n)
{
	if (n > 15)
		ft_putnbr_base_hex(n / 16);
	ft_putchar("0123456789abcdef"[n % 16]);
	return (ft_hexacount(n));
}

int	ft_putnbr_base_hexa(unsigned int n)
{
	if (n > 15)
		ft_putnbr_base_hexa(n / 16);
	ft_putchar("0123456789ABCDEF"[n % 16]);
	return (ft_hexacount(n));
}
