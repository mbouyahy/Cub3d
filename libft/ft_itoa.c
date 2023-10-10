/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:42:41 by mbouyahy          #+#    #+#             */
/*   Updated: 2022/10/10 13:05:31 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	array_len(long long int nb)
{
	int	i;

	i = 1;
	if (nb < 0)
		nb *= -1;
	while (nb >= 10)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static int	verifier(int n, int *i)
{
	if (n < 0)
	{
		*i = 1;
		return (1);
	}
	else
		return (0);
}

char	*ft_itoa(int n)
{
	char			*tab;
	unsigned int	nb;
	int				len;
	int				i;

	i = 0;
	len = array_len(n);
	if (n < 0)
		len++;
	tab = (char *)malloc(len + 1);
	if (!tab)
		return (NULL);
	tab[len] = '\0';
	if (verifier(n, &i) == 1)
	{
		n *= -1;
		tab[0] = '-';
	}
	nb = n;
	while (--len >= i)
	{
		tab[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (tab);
}
