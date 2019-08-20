/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:38:25 by tcajee            #+#    #+#             */
/*   Updated: 2019/08/20 10:19:22 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_itoa(int n)
{
	char	out[12];
	char	*new;
	int		x;
	size_t	i;

	F_(n == -2147483648, ft_strdup("-2147483648"));
	_F_(n == 0, ft_strdup("0"));
	_F(n < 0, x = n * -1);
	_(x = n);
	i = 0;
	___(x > 0, F(!!(out[i++] = (x % 10) + 48), x /= 10));
	F(n < 0, out[i++] = '-');
	F(i <= 12, out[i] = '\0');
	F_(!(new = ft_strnew(ft_strlen(out))), NULL);
	new = ft_strcpy(new, ft_strrev(out));
	return (new);
}
