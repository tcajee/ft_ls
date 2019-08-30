/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 12:43:51 by sminnaar          #+#    #+#             */
/*   Updated: 2019/08/30 12:06:25 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf_.h"

char	*ft_width(char width, va_list list)
{
	(void)list;
	return (ft_itoa(width));
}

void	ft_inc_width(int *i, int width)
{
	if (width == 0)
		*i += 1;
	if (width <= 9 && width != 0)
		*i += 2;
	if (width >= 10)
		*i += 3;
}
