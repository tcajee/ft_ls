/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:37:39 by sminnaar          #+#    #+#             */
/*   Updated: 2019/08/30 16:53:08 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf_.h"

int		ft_format_width(va_list list)
{
	int width;

	width = va_arg(list, int);
	return (width);
}

void	ft_parse(char *form, va_list list)
{
	int i;
	int width;

	i = 0;
	width = 0;
	while (form[i])
	{
		if (form[i + 1] == '.' && form[i] == '%')
		{
			i += 3;
			width = ft_format_width(list);
		}
		if (form[i] == '%')
		{
			++i;
			ft_spec(&form[i++], list, width);
		}
		if (form[i] == '\\')
		{
			ft_slash(form[++i]);
		}
		else if (form[i] != '\0') 
			ft_putchar(form[i++]);
	}
}
