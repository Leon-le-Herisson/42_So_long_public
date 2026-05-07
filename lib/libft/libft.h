/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamagere <bamagere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 00:00:53 by linux-babas       #+#    #+#             */
/*   Updated: 2026/01/14 12:34:17 by bamagere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdbool.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>

# define BLACK "\033[1;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define NC "\033[0m"
# define BOLD_RED "\033[1;31m"
# define BOLD_Y "\033[1;33m"
# define BOLD_MAG "\033[1;35m"
# define FLASH_Y "\033[5;33m"
# define FLASH_MAG "\033[5;35m"
# define FLASH_C "\033[5;36m"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*_arg_modif_________________________________________________________________*/
int			ft_atoi(const char *nptr);
char		*ft_itoa(int n);
long		ft_atoli(const char *nptr);
long long	ft_atoll(const char *nptr);
bool		ft_atoi_failed(const char *s, int nb);
char		*ft_utoa_base(unsigned long n, int base, int upper);
/*_type_verif________________________________________________________________*/
int			ft_isalnum(int a);
int			ft_isalnum_str(char *s);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int d);
int			ft_isprint(int c);
bool		ft_is_whitespace(char c);
void		ft_path_checker(char *str);
/*_memory_allocation_________________________________________________________*/
void		*ft_calloc(size_t nmemb, size_t size);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
char		*ft_strncpy(char *dest, const char *src, unsigned int n);
char		*ft_strdup(const char *s);
char		*ft_strndup(const char *s, size_t n);
char		*ft_strldup(const char *s, unsigned int start, unsigned int end);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strjoin_free(char *s1, char *s2, int free_s1, int free_s2);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		**ft_split_charset(char *str, const char *charset);
void		*ft_realloc(void *ptr, size_t size);
/*_function_pointers_________________________________________________________*/
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/*_string_manip______________________________________________________________*/
void		ft_bzero(void *s, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t size);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
char		*ft_strchr(const char *str, int c);
char		*ft_strchrr(const char *src, int c);
int			ft_strindex(const char *haystack, const char *needle);
char		*ft_strrchr(const char *str, int c);
char		*ft_strstr(const char *haystack, const char *needle);
size_t		ft_strlen(const char *str);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strnstr(const char *s1, const char *s2, size_t len);
char		*ft_strtok(char *str, const char *delim, bool skipQuote);
int			ft_tolower(int c);
int			ft_toupper(int c);
/*_tab_manip_________________________________________________________________*/
void		ft_free_tab(char **tab);
void		ft_print_tab(char **src);
char		**ft_tabcpy(char **tab);
size_t		ft_tabsize(char **tab);
/*_linked_list_______________________________________________________________*/
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstsort_alpha(t_list *lst);
t_list		*ft_lsttabcpy(char **tab);
char		**ft_lst_tabdup(t_list *src);
void		fd_printf_lst(int fd, t_list *lst);
/*_write_____________________________________________________________________*/
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_puts(const char *str);
void		ft_puts_color(char *color, char *phrase);
void		ft_puts_rainbow(char *phrase);
void		ft_gameover(void);
void		ft_gamewon(void);
#endif
