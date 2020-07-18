/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 19:13:45 by efumiko           #+#    #+#             */
/*   Updated: 2020/07/18 16:13:44 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

static int	ft_check_type(char type, t_data *data, va_list *args)
{
	if (type == 'd' || type == 'i')
		return (ft_int_type(data, args));
	if (type == 'x' || type == 'X' || type == 'u')
		return (ft_uxx_type(data, args));
	if (type == 'c' || type == '%')
		return (ft_c_type(data, args));
	if (type == 's')
		return (ft_s_type(data, args));
	if (type == 'p')
		return (ft_p_type(data, args));
	return (0);
}

int			ft_processor(t_data *data, va_list *args)
{
	char	type;
	int		length;

	type = data->type;
	length = ft_check_type(type, data, args);
	free(data);
	return (length);
}
