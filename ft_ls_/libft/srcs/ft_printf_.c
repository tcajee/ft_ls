/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 14:34:00 by sminnaar          #+#    #+#             */
/*   Updated: 2019/08/29 14:24:05 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf_.h"
#include <stdio.h>
#include <stdarg.h>

void	ft_printf_(char *format, ...)
{
	va_list	v_list;
	int		i;
	int		width;

		
	va_start(v_list, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			++i;
			width = ft_spec(&format[i], v_list);
			if (width == 0)
				i += 1;
			if (width <= 9 && width != 0)
				i += 2;
			if (width >= 10)
				i += 3;
		}
		else if (format[i] == '\\')
		{
			++i;
			ft_slash(format[i]);
		}
		ft_putchar(format[i]);
		i++;
	}
	va_end(v_list);
}
