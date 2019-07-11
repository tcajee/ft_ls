/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 09:55:21 by tcajee            #+#    #+#             */
/*   Updated: 2019/06/27 16:28:03 by tcajee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*cursor;
	char	*new;

	new = NULL;
	if (s && f)
	{
		i = 0;
		FT_(!(new = ft_strnew(ft_strlen(s))), NULL);
		cursor = new;
		while (*s)
			*cursor++ = f(i++, *s++);
	}
	return (new);
}
