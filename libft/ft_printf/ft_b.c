/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:23:36 by rfulop            #+#    #+#             */
/*   Updated: 2018/01/13 08:13:30 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_b(va_list ap, t_opt *opt)
{
	char			*str;
	unsigned int	b;

	b = va_arg(ap, unsigned int);
	str = ft_convert_base(ft_itoa(b), DEC, BIN);
	write(1, str, (int)ft_strlen(str));
	opt->len += (int)ft_strlen(str);
	free(str);
}
