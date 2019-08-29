/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 14:55:55 by sminnaar          #+#    #+#             */
/*   Updated: 2019/08/29 14:25:33 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf_.h"

int		ft_spec(char *spec, va_list list)
{
	int width;
	int spc;
	
	width = 0;
	spc = 0;
	if (ft_isdigit(*spec))
	{
		width = ft_atoi(ft_width(ft_atoi(spec), list));
		while (ft_isdigit(*spec))
			++spec;
	}
	if (*spec == 's')
		ft_s(width, list);
	if (*spec == 'd')
		ft_d(width, list);
	if (*spec == 'x')
		ft_x(width, list);
	else if (*spec == 'l')
		ft_l(width, list);
	return (width);
}
