/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 12:31:10 by efumiko           #+#    #+#             */
/*   Updated: 2020/07/18 16:35:28 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"
#include "../includes/ft_utils.h"

static int	ft_print_space(t_data *data, int str_len)
{
	int	width;
	int	count_spaces;
	int	precision_str;

	width = data->width;
	if (data->precision != -1)
		precision_str = str_len > data->precision ? data->precision : str_len;
	else
		precision_str = str_len;
	count_spaces = width > precision_str ? width - precision_str : 0;
	while (count_spaces > 0)
	{
		ft_putchar_n(' ', 1);
		count_spaces--;
	}
	return (width > precision_str ? width - precision_str : 0);
}

static int	ft_print_str(t_data *data, char *s, int str_len)
{
	int	count_print;
	int	length;

	if (data->precision != -1)
		count_print = str_len > data->precision ? data->precision : str_len;
	else
		count_print = str_len;
	length = count_print;
	while (count_print > 0)
	{
		write(1, s, 1);
		s++;
		count_print--;
	}
	return (length);
}

int			ft_s_type(t_data *data, va_list *args)
{
	char	*s;
	int		length;
	int		str_len;

	s = va_arg(*args, char*);
	s = (!s ? "(null)" : s);
	str_len = ft_strlen(s);
	length = 0;
	if (data->flag_minus == '.')
		length += ft_print_space(data, str_len);
	length += ft_print_str(data, s, str_len);
	if (data->flag_minus == '-')
		length += ft_print_space(data, length);
	return (length);
}
