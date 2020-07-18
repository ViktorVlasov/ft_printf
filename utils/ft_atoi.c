/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efumiko <efumiko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 11:18:07 by efumiko           #+#    #+#             */
/*   Updated: 2020/07/18 16:37:59 by efumiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utils.h"

int	ft_atoi(const char *str)
{
	int	nb;
	int	mark;

	mark = 0;
	nb = 0;
	while (*str == ' ' || *str == '\n' || *str == '\r' ||
		*str == '\v' || *str == '\f' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			mark = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		nb = 10 * nb + (*str++ - '0');
	if (mark == 1)
		return (-1 * nb);
	return (nb);
}
