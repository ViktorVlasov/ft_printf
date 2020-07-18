/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_parse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 13:25:09 by efumiko           #+#    #+#             */
/*   Updated: 2020/07/18 15:54:19 by efumiko          ###   ########.fr       */
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

static int	check_precison(const char *format, t_data *data, va_list *args)
{
	int sign;
	int len;

	len = 0;
	sign = -1;
	if (*format == '*')
	{
		data->precision = va_arg(*args, int);
		sign = data->precision < 0 ? 1 : 0;
		data->precision = data->precision < 0 ? -1 : data->precision;
		len += 1;
	}
	else if (ft_isdigit(*format))
	{
		len += len_from_str(format);
		data->precision = ft_atoi(format);
	}
	else
		data->precision = 0;
	if (data->flag_zero == '0' && sign != 1)
		data->flag_zero = '.';
	return (len);
}

int			ft_precision_parse(const char *format, t_data *data, va_list *args)
{
	int len;

	len = 0;
	data->precision = -1;
	if (*format == '.')
	{
		format++;
		len++;
		len += check_precison(format, data, args);
	}
	return (len);
}
