/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 19:56:07 by rfulop            #+#    #+#             */
/*   Updated: 2017/01/17 18:26:40 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_size(int n)
{
	int a;

	a = 1;
	while (n >= 10)
	{
		n = n / 10;
		++a;
	}
	return (a);
}

char			*ft_itoa(int n)
{
	int		a;
	int		sign;
	char	*res;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 0;
	if (n < 0)
	{
		sign++;
		n = n * -1;
	}
	a = ft_size(n);
	if (!(res = malloc(sizeof(char) * (a + sign + 1))))
		return (NULL);
	ft_strclr(res);
	if (sign)
		res[0] = '-';
	while (a > 0)
	{
		res[a + sign - 1] = n % 10 + '0';
		n = n / 10;
		--a;
	}
	return (res);
}
