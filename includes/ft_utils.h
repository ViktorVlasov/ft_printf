/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 21:00:31 by efumiko           #+#    #+#             */
/*   Updated: 2020/07/18 15:27:35 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include "stdlib.h"
# include "unistd.h"

int			ft_isdigit(int c);
int			ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
void		ft_putchar_n(char c, int n);
void		ft_un_putnbr(size_t n, int base, int is_upper);
void		ft_putnbr(ssize_t n);

#endif
