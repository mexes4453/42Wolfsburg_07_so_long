/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 09:37:55 by cudoh             #+#    #+#             */
/*   Updated: 2022/05/29 09:37:55 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_d(int d)
{
	int	len;

	len = 0;
	if (d < 0)
	{
		if (d < -2147483647)
		{
			len += write(1, "-2147483648", 11);
			return (len);
		}
		len += write(1, "-", 1);
		d = (int) d * -1;
	}
	len += ft_printf_nbr_base(d, 10, 0);
	return (len);
}
