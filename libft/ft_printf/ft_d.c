/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:25:12 by rfulop            #+#    #+#             */
/*   Updated: 2018/01/13 08:13:56 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_d(t_opt *opt, long long int n)
{
	char	*str;

	str = ft_itoa_ll(n);
	if (opt->prec)
		str = ft_prec(opt, str, 'd');
	if (opt->space && !opt->plus && n >= 0)
		str = ft_stradd(" ", str, 2);
	if (opt->plus && n >= 0)
		str = ft_stradd("+", str, 2);
	if (opt->width)
		str = ft_width(opt, str, 'd');
	write(1, str, (int)ft_strlen(str));
	opt->len += (int)ft_strlen(str);
	free(str);
}

void		ft_d(va_list ap, t_opt *opt, char c)
{
	long long int	n;

	if (opt->z)
		n = (size_t)ft_z(ap);
	else if (opt->j)
		n = (uintmax_t)ft_j(ap);
	else if (opt->l || c == 'D')
		n = (long long int)ft_ld(ap);
	else if (opt->ll)
		n = (long long int)ft_lld(ap);
	else if (opt->h)
		n = (short)ft_hd(ap);
	else if (opt->hh)
		n = (signed char)ft_hhd(ap);
	else
		n = va_arg(ap, int);
	if (opt->prec == -1 && !n)
	{
		opt->res = ft_strnew(1);
		opt->res = ft_no_prec(opt, opt->res, c);
		opt->len += (int)ft_strlen(opt->res);
		free(opt->res);
	}
	else
		ft_print_d(opt, n);
}
