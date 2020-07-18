/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 15:09:41 by efumiko           #+#    #+#             */
/*   Updated: 2020/07/17 12:14:03 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utils.h"

void	ft_putnbr(ssize_t n)
{
	if (n == -2147483648)
	{
		write(1, "-2", 2);
		n = 147483648;
	}
	if (n < 0)
	{
		n = -1 * n;
		write(1, "-", 1);
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar_n(n % 10 + '0', 1);
}

void	ft_un_putnbr(size_t n, int base, int is_upper)
{
	char	*buf;

	if (is_upper)
		buf = "0123456789ABCDEF";
	else
		buf = "0123456789abcdef";
	if (n / base != 0)
		ft_un_putnbr(n / base, base, is_upper);
	ft_putchar_n(buf[n % base], 1);
}
