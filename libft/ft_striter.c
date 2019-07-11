/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:02:01 by tcajee            #+#    #+#             */
/*   Updated: 2019/06/27 16:03:00 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	size_t i;
	size_t len;

	if (s && f)
	{
		i = 0;
		len = ft_strlen(s);
		while (i < len)
			f(&s[i++]);
	}
}
