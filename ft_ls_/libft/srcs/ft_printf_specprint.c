/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:12:11 by sminnaar          #+#    #+#             */
/*   Updated: 2019/08/29 14:26:27 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf_.h"

void	ft_d(int width, va_list list)
{
	char	*str;
	int		spc;

	str = ft_itoa(va_arg(list, int));
	spc = width - ft_strlen(str);
	while (spc > 0)
	{
		ft_putchar(' ');
		--spc;
	}
	ft_putstr(str);
}

void	ft_s(int width, va_list list)
{
	char	*str;
	int		spc;

	str = va_arg(list, char *);
	spc = width - ft_strlen(str);
	ft_putstr(str);
	while (spc > 0)
	{
		ft_putchar(' ');
		--spc;
	}
}

void	ft_x(int width, va_list list)
{
	char	*str;
	int		spc;

	str = ft_itoa(va_arg(list, int));
	spc = width - ft_strlen(str);
	while (spc > 0)
	{
		ft_putchar(' ');
		--spc;
	}
	ft_putstr(str);
}

void	ft_l(int width, va_list list)
{
	char	*str;
	int		spc;

	str = ft_lltoa(va_arg(list, long long));
	spc = width - ft_strlen(str);
	while (spc > 0)
	{
		ft_putchar(' ');
		--spc;
	}
	ft_putstr(str);
}