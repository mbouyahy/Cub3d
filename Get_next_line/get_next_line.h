/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:50:58 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/10/05 20:21:32 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//Biblio...
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

//define BUFFER_SIZE

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

//les fonctions principales :

char	*get_next_line(int fd);
char	*lire_ligne(int fd, char *stock);
int		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_ligne(char *stock);
char	*ft_vider(char *stock);

#endif
