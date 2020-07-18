/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 12:30:51 by efumiko           #+#    #+#             */
/*   Updated: 2020/07/18 17:37:33 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"
#include "../includes/ft_utils.h"

static int	ft_print_space(t_data *data)
{
	int	count_spaces;

	count_spaces = data->width > 0 ? data->width - 1 : 0;
	if (data->flag_zero == '0' && data->type == '%')
		ft_putchar_n('0', count_spaces);
	else
		ft_putchar_n(' ', count_spaces);
	return (count_spaces);
}

int			ft_c_type(t_data *data, va_list *args)
{
	char	c;
	int		length;

	if (data->type == 'c')
		c = (char)va_arg(*args, int);
	else
		c = '%';
	length = 1;
	if (data->flag_minus == '.')
		length += ft_print_space(data);
	write(1, &c, 1);
	if (data->flag_minus == '-')
		length += ft_print_space(data);
	return (length);
}
