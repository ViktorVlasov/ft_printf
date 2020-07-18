/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:00:47 by efumiko           #+#    #+#             */
/*   Updated: 2020/07/18 15:51:53 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parser.h"
#include "../includes/ft_utils.h"

t_data	*ft_parser(const char **format, va_list *args)
{
	t_data *data;

	if ((data = malloc(sizeof(t_data))) == NULL)
		return (NULL);
	(*format) += ft_flags_parse(*format, data);
	(*format) += ft_width_parse(*format, data, args);
	(*format) += ft_precision_parse(*format, data, args);
	if (data->flag_zero == '0' && data->flag_minus == '-')
		data->flag_zero = '.';
	if (ft_type_parse(*format, data))
		(*format)++;
	else
	{
		free(data);
		return (NULL);
	}
	return (data);
}
