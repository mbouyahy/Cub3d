/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaazouz <jlaazouz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:20:58 by jlaazouz          #+#    #+#             */
/*   Updated: 2023/10/08 21:23:02 by jlaazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

/*---------------------------*/

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

void	*ft_memset(void *s, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_bzero(void *s, size_t n);

int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *restrict dst, const char *restrict src,
			size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

/*---------------------------*/

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
int		ft_words(const char *str, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_itoa(int n);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/*---------------------------*/

int		ft_printf(const char *str, ...);
int		ft_putchar(int c);
int		ft_putstr(char *s);
int		ft_countdigit_p(unsigned int n);
int		ft_hexacount(unsigned int n);
int		ft_putnbr_base_hex(unsigned int n);
int		ft_putnbr_base_hexa(unsigned int n);
int		ft_putnbr(int n);
int		ft_putnbr_u(unsigned int n);
int		ft_ptr(unsigned long n);

/*---------------------------*/

char	*get_next_line(int fd);
int		ft_new_line_checker(char *str);
int		ft_index(char *str);
char	*ft_strjoin_(char *readed, char *buff);
char	*ft_left(char *readed);
size_t	ft_strlen_(const char *str);
/*---------------------------*/

#endif