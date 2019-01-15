/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:44:36 by rfulop            #+#    #+#             */
/*   Updated: 2018/01/13 08:13:21 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_opt	opt;

	va_start(ap, fmt);
	ft_init_ret(&opt);
	while (*fmt)
	{
		if (*fmt == '%' && *(fmt + 1) != '\0')
		{
			fmt++;
			ft_init_opt(&opt);
			fmt += ft_flag(&opt, (char *)fmt);
			fmt += ft_conv_type(ap, &opt, *(fmt + 1));
		}
		else if (*fmt != '%' && *fmt && !opt.check)
		{
			write(1, &(*fmt), 1);
			opt.len++;
		}
		fmt++;
	}
	va_end(ap);
	return (opt.len);
}
