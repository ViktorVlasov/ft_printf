/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 19:38:47 by efumiko           #+#    #+#             */
/*   Updated: 2020/07/18 15:28:35 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROCESSOR_H
# define FT_PROCESSOR_H

# include "ft_parser.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_processor(t_data *data, va_list *args);
int	ft_int_type(t_data *data, va_list *args);
int	ft_uxx_type(t_data *data, va_list *args);
int	ft_c_type(t_data *data, va_list *args);
int	ft_s_type(t_data *data, va_list *args);
int	ft_p_type(t_data *data, va_list *args);

#endif
