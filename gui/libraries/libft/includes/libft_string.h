/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_string.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 03:29:36 by nsampre           #+#    #+#             */
/*   Updated: 2017/08/17 06:19:58 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRING_H
# define LIBFT_STRING_H

# include "libft.h"

size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *src);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t nb);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *str, int c);
char			*ft_strstr(const char *str, const char *to_find);
char			*ft_strnstr(const char *str, const char *to_find, size_t len);
int				ft_strcmp(char *s1, char *s2);
int				ft_strncmp(char *s1, char *s2, size_t n);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_strnjoin(char const *s1, char const *s2, ssize_t len);
char			*ft_strupcase(char *str);
char			*ft_strlowcase(char *str);
char			*ft_strcapitalize(char *str);
char			*ft_strndup(char *s, size_t len);
char			**ft_cut_string(char *s, char c, int occurence);
void			ft_trim_quotestr(char *line);
char			*ft_strreplace(char *orig, char *rep, char *with);
int				ft_str_is_number(char *input);
int				ft_str_fits_int(char *input);
void			ft_trim_quotestr(char *line);
void			ft_escape(char *line, char escape, char real_value);
int				ft_is_quotestring(char *s);
char			*ft_strreplace_once(char *orig, char *rep, char *with);
int				ft_is_whitestring(char *str);
char			*ft_post_realloc_str(char *str, char *add);

#endif
