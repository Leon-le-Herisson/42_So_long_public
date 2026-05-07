/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printfs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamagere <bamagere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 00:01:45 by linux-babas       #+#    #+#             */
/*   Updated: 2026/01/06 12:48:37 by bamagere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_PRINTFS_H
# define MY_PRINTFS_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

/*###   FT_PRINT_TAB   ###*/
void	ft_print_tab(char **src);
/*###   FD_PRINTF_LST   ###*/
void	fd_printf_lst(int fd, t_list *lst);

/*###  FT_PRINTF_BONUS   ###*/
/*_struct */
typedef struct s_format
{
	char	form;
	int		flag_minus;
	int		flag_zero;
	int		flag_hash;
	int		flag_space;
	int		flag_plus;
	int		width;
	int		precision;
}	t_format;
/*_dispatch_&_parsing */
int		ft_printf(const char *format, ...);
int		parse_bonus(const char *s, int i, t_format *f, va_list args);
char	*join2(const char *a, const char *b);
/*_sign */
char	*build_signed_core(t_format *f, long n);
char	*build_unsigned_core(t_format *f, unsigned long n, int base, int upper);
/*_width_padding */
int		write_padded_left(const char *core, int width);
int		write_padded_right(const char *core, int width);
int		write_zero_left(const char *prefix, const char *digits, int width);
/*_type_printer */
int		print_char_bonus(t_format *f, char c);
int		print_str_bonus(t_format *f, const char *s);
int		print_int_bonus(t_format *f, long n);
int		print_uint_bonus(t_format *f, unsigned int n);
int		print_ptr_bonus(t_format *f, unsigned long p);
int		print_hex_bonus(t_format *f, unsigned int n, int upper);
int		print_percent_bonus(t_format *f);
char	*get_hex_prefix(int upper);

/*###   FD_PRINTF   ###*/
int		fd_printf(int fd, const char *format, ...);
int		fd_print_char(int fd, int arg, int i);
int		fd_print_nb(int fd, int arg, int i);
int		fd_print_p(int fd, size_t arg, int i);
int		fd_print_nb_base_x(int fd, size_t arg, int i);
int		fd_print_nb_base_bigx(int fd, size_t arg, int i);
int		fd_print_nb_u(int fd, unsigned int arg, int i);

#endif
