/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:01:43 by mbouyahy          #+#    #+#             */
/*   Updated: 2022/10/14 20:08:24 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list	*lst, void	*(*f)(void *), void (*del)(void *))
{
	t_list	*nliste;
	t_list	*n;

	if (!lst || !f || !del)
		return (NULL);
	nliste = NULL;
	while (lst)
	{
		n = ft_lstnew(f(lst->content));
		if (!n)
		{
			ft_lstclear(&nliste, del);
		}
		ft_lstadd_back(&nliste, n);
		lst = lst->next;
	}
	return (nliste);
}
