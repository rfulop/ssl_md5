/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intfill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 14:16:37 by rfulop            #+#    #+#             */
/*   Updated: 2016/06/28 14:19:30 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_intfill(int *tab, int size)
{
	int	a;

	a = 0;
	while (a < size)
	{
		tab[a] = 0;
		++a;
	}
}
