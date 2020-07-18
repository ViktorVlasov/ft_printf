/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 23:15:30 by efumiko           #+#    #+#             */
/*   Updated: 2020/07/18 15:55:07 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parser.h"

int	ft_type_parse(const char *format, t_data *data)
{
	if (*format == 'd')
		data->type = 'd';
	else if (*format == 'i')
		data->type = 'i';
	else if (*format == 'c')
		data->type = 'c';
	else if (*format == 's')
		data->type = 's';
	else if (*format == 'p')
		data->type = 'p';
	else if (*format == 'x')
		data->type = 'x';
	else if (*format == 'X')
		data->type = 'X';
	else if (*format == '%')
		data->type = '%';
	else if (*format == 'u')
		data->type = 'u';
	else
		return (0);
	return (1);
}
