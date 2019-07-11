/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:38:25 by tcajee            #+#    #+#             */
/*   Updated: 2019/06/28 13:45:58 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*string;
	int		x;
	size_t	i;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	else if (n < 0)
		x = n * -1;
	else
		x = n;
	string = ft_strnew(12);
	FT_(!string, NULL);
	while (x > 0)
	{
		string[i++] = (x % 10) + 48;
		x /= 10;
	}
	if (n < 0)
		string[i] = '-';
	string = ft_strcpy(ft_strnew(ft_strlen(string)), ft_strrev(string));
	return (string);
}
