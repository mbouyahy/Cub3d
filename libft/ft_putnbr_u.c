/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz < jlaazouz@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 22:12:16 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/03/23 14:54:50 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_u(unsigned int n)
{
	if (n > 9)
		ft_putnbr_u(n / 10);
	ft_putchar((n % 10) + 48);
	return (ft_countdigit_p((unsigned int)n));
}
