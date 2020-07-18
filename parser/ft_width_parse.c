/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 13:22:38 by efumiko           #+#    #+#             */
/*   Updated: 2020/07/18 15:38:10 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parser.h"
#include "../includes/ft_utils.h"

static int	len_from_str(const char *format)
{
	int len;

	len = 0;
	while (ft_isdigit(*format))
	{
		len++;
		format++;
	}
	return (len);
}

int			ft_width_parse(const char *format, t_data *data, va_list *args)
{
	int len;

	len = 0;
	if (*format == '*')
	{
		data->width = va_arg(*args, int);
		if (data->width < 0)
		{
			data->width = data->width * (-1);
			data->flag_minus = '-';
		}
		len += 1;
	}
	else if (ft_isdigit(*format))
	{
		len = len_from_str(format);
		data->width = ft_atoi(format);
	}
	else
		data->width = 0;
	return (len);
}
