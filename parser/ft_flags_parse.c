/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:58:08 by efumiko           #+#    #+#             */
/*   Updated: 2020/07/18 15:50:52 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parser.h"

int	ft_flags_parse(const char *format, t_data *data)
{
	int len;

	len = 0;
	data->flag_minus = '.';
	data->flag_zero = '.';
	while (*format == '0' || *format == '-')
	{
		if (*format == '0')
			data->flag_zero = '0';
		else if (*format == '-')
			data->flag_minus = '-';
		format++;
		len++;
	}
	return (len);
}
