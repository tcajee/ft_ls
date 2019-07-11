/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:19:54 by tcajee            #+#    #+#             */
/*   Updated: 2019/06/17 11:06:15 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *cursor;
	char *new;

	new = NULL;
	if (s && f)
	{
		FT_(!(new = ft_strnew(ft_strlen(s))), NULL);
		cursor = new;
		while (*s)
			*cursor++ = f(*s++);
	}
	return (new);
}
