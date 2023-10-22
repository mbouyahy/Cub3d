/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz < jlaazouz@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:24:18 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/03/23 14:45:54 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_conversions(va_list arg, char *str)
{
	int	count;

	count = 0;
	if (*str == 'c')
		count = ft_putchar(va_arg(arg, int));
	if (*str == 's')
		count = ft_putstr(va_arg(arg, char *));
	if (*str == 'd')
		count = ft_putnbr(va_arg(arg, int));
	if (*str == 'i')
		count = ft_putnbr(va_arg(arg, int));
	if (*str == 'u')
		count = ft_putnbr_u(va_arg(arg, unsigned int));
	if (*str == 'x')
		count = ft_putnbr_base_hex(va_arg(arg, unsigned int));
	if (*str == 'X')
		count = ft_putnbr_base_hexa(va_arg(arg, unsigned int));
	if (*str == 'p')
		count = ft_ptr(va_arg(arg, unsigned long));
	if (*str == '%')
		count = ft_putchar('%');
	return (count);
}

int	ft_exist(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		ret;
	int		conv;
	va_list	arg;

	va_start(arg, str);
	i = 0;
	ret = 0;
	conv = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (ft_exist(*(str + i + 1)))
				i++;
			ret += ft_conversions(arg, (char *)(str + i));
			conv += 2;
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (i - conv + ret);
}
