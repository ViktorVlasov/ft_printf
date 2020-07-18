/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 15:23:59 by efumiko           #+#    #+#             */
/*   Updated: 2020/07/18 16:01:13 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"
#include "../includes/ft_utils.h"

static int	get_len_int_nbr(int nbr)
{
	int len;

	len = (nbr == 0 ? 1 : 0);
	if (nbr < 0)
		len += 1;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

static int	ft_print_space(t_data *data, int nbr_len, ssize_t nbr)
{
	int		width;
	int		count_spaces;
	char	symb;
	int		count_prec;

	width = data->width;
	if (nbr < 0)
		count_prec = data->precision >= nbr_len ? data->precision + 1 : nbr_len;
	else
		count_prec = data->precision >= nbr_len ? data->precision : nbr_len;
	count_spaces = width > count_prec ? width - count_prec : 0;
	symb = data->flag_zero == '.' ? ' ' : '0';
	ft_putchar_n(symb, count_spaces);
	return (count_spaces);
}

static int	ft_print_zero(t_data *data, int nbr_len, ssize_t nbr)
{
	int	precision;
	int	count_zero;

	precision = data->precision;
	if (nbr >= 0)
		count_zero = precision > nbr_len ? precision - nbr_len : 0;
	else
	{
		nbr_len--;
		count_zero = precision > nbr_len ? precision - nbr_len : 0;
	}
	ft_putchar_n('0', count_zero);
	return (count_zero);
}

int			ft_int_type(t_data *data, va_list *args)
{
	ssize_t	nbr;
	int		length;
	int		nbr_len;

	nbr = va_arg(*args, int);
	nbr_len = get_len_int_nbr(nbr);
	if (data->precision == 0 && nbr == 0)
		nbr_len = 0;
	length = nbr_len;
	data->flag_zero == '0' && nbr < 0 ? ft_putchar_n('-', 1) : 0;
	if (data->flag_minus == '.')
		length += ft_print_space(data, nbr_len, nbr);
	data->flag_zero == '.' && nbr < 0 ? ft_putchar_n('-', 1) : 0;
	length += ft_print_zero(data, nbr_len, nbr);
	if (!(data->precision == 0 && nbr == 0))
		nbr >= 0 ? ft_putnbr(nbr) : ft_putnbr(nbr * (-1));
	if (data->flag_minus == '-')
		length += ft_print_space(data, nbr_len, nbr);
	return (length);
}
