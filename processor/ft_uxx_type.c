/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uxx_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 09:47:50 by efumiko           #+#    #+#             */
/*   Updated: 2020/07/19 09:42:24 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"
#include "../includes/ft_utils.h"

static void	get_len_uint_nbr(size_t nbr, int base, int *len)
{
	if (nbr / base != 0)
		get_len_uint_nbr(nbr / base, base, len);
	(*len)++;
}

static int	ft_print_space(t_data *data, int nbr_len)
{
	int		width;
	int		count_spaces;
	char	symb;
	int		count_prec;

	width = data->width;
	count_prec = data->precision > nbr_len ? data->precision : nbr_len;
	count_spaces = width > count_prec ? width - count_prec : 0;
	symb = data->flag_zero == '.' ? ' ' : '0';
	ft_putchar_n(symb, count_spaces);
	return (count_spaces);
}

static int	ft_print_zero(t_data *data, int nbr_len)
{
	int	precision;
	int	count_zero;

	precision = data->precision;
	count_zero = precision > nbr_len ? precision - nbr_len : 0;
	ft_putchar_n('0', count_zero);
	return (count_zero);
}

int			ft_uxx_type(t_data *data, va_list *args)
{
	size_t	nbr;
	int		length;
	int		nbr_len;
	int		is_upper;
	int		base;

	is_upper = data->type == 'X' ? 1 : 0;
	base = data->type == 'u' ? 10 : 16;
	nbr = va_arg(*args, unsigned int);
	nbr_len = 0;
	get_len_uint_nbr(nbr, base, &nbr_len);
	if (data->precision == 0 && nbr == 0)
		nbr_len = 0;
	length = nbr_len;
	if (data->flag_minus == '.')
		length += ft_print_space(data, nbr_len);
	length += ft_print_zero(data, nbr_len);
	if (!(data->precision == 0 && nbr == 0))
		ft_un_putnbr(nbr, base, is_upper);
	if (data->flag_minus == '-')
		length += ft_print_space(data, nbr_len);
	return (length);
}
