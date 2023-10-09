/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cup3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:22:28 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/06 15:20:07 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUP3D_H
#define CUP3D_H

#include <stdlib.h>
# include <fcntl.h>
#include "./Get_next_line/get_next_line.h"

typedef struct t_list
{
    char *stock;
    struct t_list *next;
} list;

list	*ft_lstnew(void	*content);
char	*ft_strdup(const char *s1);
list	*ft_lstlast(list *lst);
void	ft_lstadd_back(list **lst, list *new);
list    *fill_stock(void);
char	*ft_strtrim(char const *s1, char const *set);
#endif