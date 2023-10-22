/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz < jlaazouz@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:26:21 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/03/23 14:55:04 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int n)
{
	int	sign;

	sign = 1;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else
	{
		if (n < 0)
		{
			sign = -1;
			ft_putchar('-');
			n = -n;
		}
		if (n > 9)
			ft_putnbr(n / 10);
		ft_putchar((n % 10) + 48);
	}
	if (sign < 0)
		return (ft_countdigit_p(n) + 1);
	return (ft_countdigit_p(n));
}
