/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 23:18:14 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/19 22:10:25 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"

# include <stdarg.h>

# define COUNT format->count
# define FLAG format->flags
# define WIDTH format->width
# define IS_PRECISION format->is_precision
# define PRECISION format->precision
# define PRECISION_TO_FILL format->precision_to_fill
# define IS_NEGATIVE format->is_neg
# define LEN format->len
# define LEN_WIDE format->len_wide
# define LEN_WIDE_PUT format->len_wide_put
# define LEN_FILL_LEFT format->len_fill_left
# define LEN_FILL_RIGHT format->len_fill_right
# define FILL_BLANKS_LEFT format->fill_blanks_left
# define FILL_BLANKS_RIGHT format->fill_blanks_right
# define FILL_ZEROS_LEFT format->fill_zeros_left
# define IS_OCTOTHORP format->is_hash_flag
# define HEX_TYPE format->hex
# define NO_FORMAT format->no_format
# define TYPE format->type

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

typedef struct	s_format
{
	int			fd;
	int			count;
	char		flags[6];
	int			width;
	int			is_precision;
	int			precision;
	int			precision_to_fill;
	int			is_neg;
	int			len;
	int			len_wide;
	int			len_wide_put;
	int			len_fill_left;
	int			len_fill_right;
	int			fill_blanks_left;
	int			fill_blanks_right;
	int			fill_zeros_left;
	int			is_hash_flag;
	int			hex;
	char		no_format;
	char		type[4];
}				t_format;

# ifndef GLOBAL_VAR_PRINTF
#  define GLOBAL_VAR_PRINTF

extern t_format	*g_format_derivate;

# endif

int				ft_printf(char *s, ...);
int				ft_fprintf(int fd, char *s, ...);

void			ft_get_params(t_format *format, char *s, va_list arg);
int				ft_putchar_count(char c, int dispay);
int				ft_put_wchar_count(wchar_t wc, int display);
int				ft_put_precision(t_format *format);
int				ft_put_blanks(int total);
int				ft_put_zeros(int total);
int				ft_put_hex_long(unsigned long int hex, int disp, t_format *f);

int				ft_get_count(char *s);
char			ft_get_flags(char *s, char flag);
int				ft_get_width(char *s);
int				ft_get_precision(char *s);
char			*ft_get_convertion(char *s);
char			*ft_get_type(char *s, t_format *format);

int				ft_isflag(char c);
int				ft_istype(char c);
int				ft_isconv(char c);
int				ft_is_precision(char *s);

int				ft_count_flag(char *s);
int				ft_count_width(char *s);
int				ft_count_precision(char *s);
int				ft_count_conversion(char *s);

int				ft_handle_no_format(t_format *format);

int				ft_handle_args(va_list arg, t_format *format);
int				ft_handle_args_part_two(va_list arg, t_format *format);
int				ft_handle_args_part_three(va_list arg, t_format *format);
int				ft_handle_args_part_four(va_list arg, t_format *format);
int				ft_handle_args_part_five(va_list arg, t_format *format);
int				ft_handle_args_part_six(va_list arg, t_format *format);
int				ft_handle_args_part_seven(va_list arg, t_format *format);
int				ft_handle_args_part_eight(va_list arg, t_format *format);

int				ft_handle_int(va_list arg, t_format *format);
int				ft_handle_long(va_list arg, t_format *format);
int				ft_handle_long_long(va_list arg, t_format *format);
int				ft_handle_intmax_t(va_list arg, t_format *format);
int				ft_handle_short(va_list arg, t_format *format);
int				ft_handle_ssize_t(va_list arg, t_format *format);
int				ft_handle_signed_char(va_list arg, t_format *format);

int				ft_handle_unsigned_int(va_list arg, t_format *format);
int				ft_handle_unsigned_long(va_list arg, t_format *format);
int				ft_handle_unsigned_long_long(va_list arg, t_format *format);
int				ft_handle_uintmax_t(va_list arg, t_format *format);
int				ft_handle_unsigned_short(va_list arg, t_format *format);
int				ft_handle_unsigned_char(va_list arg, t_format *format);

int				ft_handle_octal(va_list arg, t_format *format);
int				ft_handle_octal_long(va_list arg, t_format *format);
int				ft_handle_octal_long_long(va_list arg, t_format *format);
int				ft_handle_octal_short(va_list arg, t_format *format);
int				ft_handle_octal_char(va_list arg, t_format *format);

int				ft_handle_binary(va_list arg, t_format *format);
int				ft_handle_binary_long(va_list arg, t_format *format);
int				ft_handle_binary_long_long(va_list arg, t_format *format);
int				ft_handle_binary_short(va_list arg, t_format *format);
int				ft_handle_binary_char(va_list arg, t_format *format);

int				ft_handle_hex_min(va_list arg, t_format *format);
int				ft_handle_hex_min_long(va_list arg, t_format *format);
int				ft_handle_hex_min_long_long(va_list arg, t_format *format);
int				ft_handle_hex_min_short(va_list arg, t_format *format);
int				ft_handle_hex_min_char(va_list arg, t_format *format);
int				ft_handle_hex_maj(va_list arg, t_format *format);
int				ft_handle_hex_maj_long(va_list arg, t_format *format);
int				ft_handle_hex_maj_long_long(va_list arg, t_format *format);
int				ft_handle_hex_maj_short(va_list arg, t_format *format);
int				ft_handle_hex_maj_char(va_list arg, t_format *format);

int				ft_handle_char(va_list arg, t_format *format);
int				ft_handle_str(va_list arg, t_format *format);
int				ft_handle_wchar(va_list arg, t_format *format);
int				ft_handle_wstr(va_list arg, t_format *format);
int				ft_handle_pointer(va_list arg, t_format *format);
int				ft_handle_percent(t_format *format);

void			ft_init_len_count(t_format *format);

void			ft_int_get_fill_left(t_format *format);
void			ft_int_get_fill_right(t_format *format);
int				ft_int_write_left(t_format *format);
int				ft_int_write_right(t_format *format);

void			ft_uint_get_fill_left(t_format *format);
void			ft_uint_get_fill_right(t_format *format);
int				ft_uint_write_left(t_format *format);
int				ft_uint_write_right(t_format *format);

void			ft_hex_get_fill_left(t_format *format);
void			ft_hex_get_fill_right(t_format *format);
int				ft_hex_write_left(t_format *format, int count);
int				ft_hex_write_right(t_format *format);

void			ft_octal_get_fill_left(t_format *format);
void			ft_octal_get_fill_right(t_format *format);
int				ft_octal_write_left(t_format *format, int count);
int				ft_octal_write_right(t_format *format);

void			ft_char_get_fill_left(t_format *format);
void			ft_char_get_fill_right(t_format *format);
int				ft_char_write_left(t_format *format);
int				ft_char_write_right(t_format *format);

#endif
