/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_convertion.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 18:32:46 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/01 07:08:49 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_CONVERTION_H
# define LIBFT_CONVERTION_H

# include "libft.h"

int				ft_atoi(const char *str);
long long		ft_atoll(const char *str);
char			*ft_xtoa(int n);
char			*ft_itoa(int n);
double			ft_atod(char *str);
int				ft_xtoi(char *str);

#endif
