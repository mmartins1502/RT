/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qselle <qselle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 16:06:44 by qselle            #+#    #+#             */
/*   Updated: 2017/12/10 13:17:41 by tdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

typedef struct	s_type
{
	int			h;
	int			hh;
	int			l;
	int			ll;
	int			j;
	int			z;
}				t_type;

typedef struct	s_flag
{
	int			diez;
	int			plus;
	int			minus;
	int			space;
	int			zero;
	int			zero_percent;
	int			point;
	int			percent;
}				t_flag;

typedef struct	s_nb
{
	char		c;
	unsigned	wc;
	void		*s;
	void		*p;
	intmax_t	d_i;
	uintmax_t	oux;
}				t_nb;

typedef struct	s_printf
{
	t_flag		flag;
	t_type		type;
	t_nb		nb;
	int			fd;
	int			nb_z;
	int			nb_s;
	int			count;
	int			size_len;
	int			index;
	int			precision;
}				t_printf;

int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
char			*ft_itoa_base(uintmax_t nb, unsigned int base);
char			*ft_itoa_base_x(uintmax_t nb, unsigned int base);
int				ft_abs(int nb);
size_t			ft_strwlen(unsigned *s);
size_t			ft_strlenlen(const char **s);
void			read_null(t_printf *pf, char c);
void			ft_putwstr_pf(wchar_t *s, t_printf *pf);
void			ft_putstr_pf(char const *s, t_printf *pf);
void			ft_putchar_pf(char c, t_printf *pf);
void			ft_putstr_lim_pf(char const *str, int size, t_printf *pf);
void			ft_putwstr_lim_pf(wchar_t *str, int size, t_printf *pf);
void			ft_putnchar_pf(char c, int n, t_printf *pf);
void			ft_putwchar_pf(wchar_t c, t_printf *pf);
void			read_wstring(t_printf *pf);
void			good_arg(char *format, va_list ap, t_printf *pf);
char			*run_type(char *format, t_printf *pf);
void			read_char(t_printf *pf);
void			read_wchar(t_printf *pf);
void			read_string(t_printf *pf);
void			read_d_i(t_printf *pf);
void			read_pointer(t_printf *pf);
void			read_hex(t_printf *pf);
void			read_u(t_printf *pf);
void			read_hexx(t_printf *pf);
void			read_octal(t_printf *pf);
void			read_percent(t_printf *pf);
char			*check_convert(char *format, t_printf *pf);
char			*check_precision(char *format, t_printf *pf);
char			*parsing(char *format, t_printf *pf, va_list ap);
char			*check_flag(char *format, t_printf *pf);
char			*check_len(char *format, t_printf *pf);
void			read_unint(va_list ap, t_printf *pf);
void			read_long(va_list ap, t_printf *pf);
void			read_unsigned_int(va_list ap, t_printf *pf);
void			ft_putadr_pf(char const *s, t_printf *pf);
int				check_nothing_u(t_printf *pf);
int				calcul_space_u(t_printf *pf, intmax_t a, intmax_t without,
		int nb_zero);
int				calcul_zero_u(t_printf *pf, intmax_t a, intmax_t without);
char			*convertl_bis(t_printf *pf, char *format);
char			*converth_bis(t_printf *pf, char *format);
void			wildcard_bonus(t_printf *p, va_list ap);
char			*ft_itoa_pf(intmax_t n);

#endif
