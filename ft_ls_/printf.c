/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 14:34:00 by sminnaar          #+#    #+#             */
/*   Updated: 2019/09/03 11:55:25 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf_.h"

void	ft_d(int width, va_list list)
{
	char	*str;
	int		spc;

	str = ft_itoa(va_arg(list, int));
	spc = width - ft_strlen(str);
	while (spc--)
		ft_putchar(' ');
	ft_putstr(str);
	free(str);
}

void	ft_s(int width, va_list list)
{
	char	*str;
	int		spc;

	str = va_arg(list, char *);
	spc = width - ft_strlen(str);
	ft_putstr(str);
	while (spc--)
		ft_putchar(' ');
}

void	ft_x(int width, va_list list)
{
	char	*str;
	int		spc;

	str = ft_itoa(va_arg(list, int));
	spc = width - ft_strlen(str);
	while (spc--)
		ft_putchar(' ');
	ft_putstr(str);
	free(str);
}

void	ft_l(int width, va_list list)
{
	char	*str;
	int		spc;

	str = ft_lltoa(va_arg(list, long long));
	spc = width - ft_strlen(str);
	while (spc--)
		ft_putchar(' ');
	ft_putstr(str);
	free(str);
}

void	ft_spec(char *spec, va_list list, int width)
{
	if (*spec == 's')
		ft_s(width, list);
	if (*spec == 'd')
		ft_d(width, list);
	if (*spec == 'x')
		ft_x(width, list);
	else if (*spec == 'l')
		ft_l(width, list);
}

void	ft_slash(char id)
{
	if (id == 'n')
		ft_putchar('\n');
	else if (id == 't')
		ft_putchar('\t');
	else if (id == 'b')
		ft_putchar('\b');
	else if (id == 'a')
		ft_putchar('\a');
	else if (id == 'v')
		ft_putchar('\v');
	else if (id == 'f')
		ft_putchar('\f');
	else if (id == 'r')
		ft_putchar('\r');
}

void	ft_printf_(char *format, ...)
{
	int i;
	int width;
	va_list	v_list;

	i = 0;
	width = 0;
	va_start(v_list, format);
	while (form[i])
	{
		if (form[i] == '%')
		{
			if (form[i + 1] == '.')
			{
				width = va_arg(list, int);
				i += 2;
			}
			if (form[i] == '%')
			{
				++i;
				ft_spec(&form[i++], list, width);
			}
		}
		else if (form[i] == '\\')
			ft_slash(form[++i]);
		else if (form[i] != '\0') 
			ft_putchar(form[i++]);
	}
	va_end(v_list);
}
