/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz < jlaazouz@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:06:53 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/03/23 14:46:00 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countptr(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

void	ft_putptr(unsigned long n)
{
	if (n > 15)
		ft_putptr(n / 16);
	ft_putchar("0123456789abcdef"[n % 16]);
}

int	ft_ptr(unsigned long n)
{
	int	a;

	write(1, "0x", 2);
	ft_putptr(n);
	a = ft_countptr(n);
	return (a + 2);
}
