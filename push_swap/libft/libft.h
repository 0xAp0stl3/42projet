/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:51:51 by mrocher           #+#    #+#             */
/*   Updated: 2024/01/24 08:39:16 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_atoi(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *str, int c, size_t n);
void	ft_putchar_fd(const char c, int fd);
void	ft_putstr_fd(const char *s, int fd);
size_t	ft_strlen(const char *s);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_tolower(int c);
int		ft_toupper(int c);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strnstr(const char *strsearch, const char *substr, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
char	*ft_strnstr(const char *strsearch, const char *substr, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_memmove(void *dest, const void *src, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strrchr(const char *s, int c);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int nb, int fd);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
int		ft_print_c(char c);
int		ft_print_percent(void);
void	ft_srchex(unsigned long long n, const char *hexa);
int		ft_print_p(void *ptr);
int		ft_print_u(unsigned int n);
int		ft_print_nbr(int n);
int		ft_print_x(unsigned int n, int format);
int		ft_printf(const char *format, ...);
int		ft_print_s(char *str);
char	*ft_strcpy(char *dest, const char *src);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void*(*f)(void *), void (*del)(void *));

#endif