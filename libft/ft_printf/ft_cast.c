/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:13:03 by rfulop            #+#    #+#             */
/*   Updated: 2018/01/13 08:13:45 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned short			ft_h(va_list ap)
{
	unsigned short n;

	n = va_arg(ap, unsigned int);
	return (n);
}

unsigned char			ft_hh(va_list ap)
{
	unsigned char n;

	n = va_arg(ap, unsigned int);
	return (n);
}

unsigned long int		ft_l(va_list ap)
{
	unsigned long int n;

	n = va_arg(ap, unsigned long int);
	return (n);
}

unsigned long long int	ft_ll(va_list ap)
{
	unsigned long long int n;

	n = va_arg(ap, unsigned long long int);
	return (n);
}
