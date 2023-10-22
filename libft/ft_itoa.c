/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz < jlaazouz@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:13:39 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/04/11 19:34:39 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countdigit(long long n)
{
	if (n / 10 == 0)
		return (1);
	return (1 + ft_countdigit(n / 10));
}

char	*ft_maxint(int n, int count)
{
	char	*arr;
	int		i;

	n /= 10;
	n *= -1;
	arr = (char *)malloc((count + 2) * sizeof(char));
	if (!arr)
		return (NULL);
	arr[0] = '-';
	arr[count + 1] = 0;
	arr[count] = '8';
	i = 0;
	while (i < count - 1)
	{
		arr[count - 1 - i] = (n % 10) + 48;
		n /= 10;
		i++;
	}
	return (arr);
}

char	*ft_isneg(int n, int count)
{
	char	*arr;
	int		i;

	if (n == -2147483648)
		return (ft_maxint(n, count));
	n *= -1;
	arr = (char *)malloc((count + 2) * sizeof(char));
	if (!arr)
		return (NULL);
	arr[0] = '-';
	arr[count + 1] = 0;
	i = 0;
	while (i < count)
	{
		arr[count - i] = (n % 10) + 48;
		n /= 10;
		i++;
	}
	return (arr);
}

char	*ft_itoa(int n)
{
	char	*arr;
	int		i;
	int		num;

	num = ft_countdigit(n);
	if (n < 0)
		return (ft_isneg(n, num));
	arr = (char *)malloc((num + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	arr[num] = 0;
	i = 0;
	while (i < num)
	{
		arr[num - 1 - i] = (n % 10) + 48;
		n /= 10;
		i++;
	}
	return (arr);
}
