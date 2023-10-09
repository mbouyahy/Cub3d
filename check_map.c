/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:10:22 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/06 15:18:53 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cup3d.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*s;
	char	*d;

	i = 0;
	j = 0;
	s = (char *)s1;
	while (s[j])
		j++;
	d = (char *)malloc(j + 1);
	if (!d)
		return (NULL);
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

list	*ft_lstlast(list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(list **lst, list *new)
{
	list	*t;

	if (!lst || !new)
		return ;
	if (*lst)
	{
		t = ft_lstlast(*lst);
		t->next = new;
	}
	else
		*lst = new;
}

list	*ft_lstnew(void	*content)
{
	list	*newlist;

	newlist = (list *)malloc(sizeof(list));
	if (!newlist)
		return (NULL);
	newlist->stock = content;
	newlist->next = NULL;
	return (newlist);
}

list    *fill_stock(void)
{
    int fd;
    char *stock;
    list *map;

    map = NULL;
    fd = open("maps", O_RDWR, 777);
    stock = get_next_line(fd);
    while (stock != NULL)
    {
        if (stock)
            ft_lstadd_back(&map, ft_lstnew(ft_strdup(stock)));
        stock = get_next_line(fd);
    }
    close(fd);
    return (map);
}

static int	verifier(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	firstset(const char	*s1, const char *set)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s1[i])
	{
		if (verifier(set, s1[i]) == 1)
		{
			i++;
			count++;
		}
		else
			return (count);
	}
	return (count);
}

static int	lastset(const char	*s1, const char *set)
{
	int	i;
	int	count;

	i = ft_strlen(s1) - 1;
	count = 0;
	while (i >= 0 && s1[i])
	{
		if (verifier(set, s1[i]) == 1)
		{
			i--;
			count++;
		}
		else
			return (count);
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		size;
	char	*res;
	int		j;
	int		x;

	x = 0;
	if (!s1 || !set)
		return (NULL);
	i = firstset(s1, set);
	j = lastset(s1, set);
	if (i == j && j == (int)ft_strlen(s1))
		res = (char *)malloc(1);
	else
	{
		size = ft_strlen(s1) - i - j;
		res = (char *)malloc(size + 1);
		if (!res)
			return (NULL);
		size = ft_strlen(s1);
		while (s1[i] && i < size - j)
			res[x++] = s1[i++];
	}
	res[x] = '\0';
	return (res);
}