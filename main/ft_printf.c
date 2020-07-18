/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 17:48:35 by efumiko           #+#    #+#             */
/*   Updated: 2020/07/18 16:42:12 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parser.h"
#include "../includes/ft_printf.h"
#include "../includes/ft_processor.h"
#include "../includes/ft_utils.h"

static int	write_to_perc(const char **format, int *length)
{
	int	i;

	i = 0;
	while (**format && **format != '%')
	{
		write(1, *format, 1);
		(*format)++;
		i++;
	}
	*length += i;
	if (**format == '%')
	{
		(*format)++;
		return (1);
	}
	return (0);
}

int			ft_printf(const char *format, ...)
{
	va_list	args;
	int		length;
	t_data	*data;
	int		flag;

	va_start(args, format);
	length = 0;
	flag = 0;
	while (*format && (flag != -1) && write_to_perc(&format, &length))
	{
		if ((data = ft_parser(&format, &args)) != NULL)
		{
			length += ft_processor(data, &args);
		}
		else if (*format)
			flag = -1;
	}
	va_end(args);
	if (flag == -1)
		return (-1);
	return (length);
}
