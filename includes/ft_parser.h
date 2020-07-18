/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 19:41:58 by efumiko           #+#    #+#             */
/*   Updated: 2020/07/18 16:52:51 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include <stdarg.h>

typedef	struct		s_data
{
	unsigned char	flag_zero;
	unsigned char	flag_minus;
	int				width;
	int				precision;
	char			type;
}					t_data;

t_data				*ft_parser(const char **format, va_list *args);
int					ft_flags_parse(const char *format, t_data *data);
int					ft_width_parse(const char *format, t_data *data,\
									va_list *args);
int					ft_precision_parse(const char *format, t_data *data,\
									va_list *args);
int					ft_type_parse(const char *format, t_data *data);

#endif
